#include <unordered_map>
#include "simplifier.h"
#include "utils.h"
#include "evaluator.h"

Node *Simplifier::simplify(Node *root)
{
    if (!root)
    {
        return nullptr;
    }

    root->set_left(simplify(root->get_left()));
    root->set_right(simplify(root->get_right()));

    // If both are numbers
    if (root->get_left() &&
        root->get_right() &&
        Utils::is_number(root->get_left()->get_value()) &&
        Utils::is_number(root->get_right()->get_value()))
    {
        Evaluator eval;
        std::unordered_map<std::string, double> temp;
        std::string res = Utils::double_to_string(eval.evaluate(root, temp));

        return new Node(res);
    }

    std::string op = root->get_value();

    Node *left = root->get_left();
    Node *right = root->get_right();

    if (op == "+")
    {
        if (left && left->get_value() == "0")
        {
            return right;
        }
        if (right && right->get_value() == "0")
        {
            return left;
        }
    }

    if (op == "-")
    {
        if (left && left->get_value() == "0")
        {
            return right;
        }

        if (left && right->get_value() == "0")
        {
            return left;
        }
    }

    if (op == "*")
    {
        if (left && left->get_value() == "1")
        {
            return right;
        }

        if (right && right->get_value() == "1")
        {
            return left;
        }

        if (left && left->get_value() == "0")
        {
            return new Node("0");
        }

        if (right && right->get_value() == "0")
        {
            return new Node("0");
        }
    }

    if (op == "/" && right && right->get_value() == "1")
    {
        return left;
    }

    if (op == "^" && right && right->get_value() == "0")
    {
        return new Node("1");
    }

    if (op == "^" && right && right->get_value() == "1")
    {
        return left;
    }

    return root;
}

Node *Simplifier::power_rules(Node *root)
{
    if (!root)
    {
        return nullptr;
    }

    root->set_left(power_rules(root->get_left()));
    root->set_right(power_rules(root->get_right()));

    Node *left = root->get_left();
    Node *right = root->get_right();

    // Helper to check if node is a number
    auto is_num = [&](Node *n)
    { return n && Utils::is_number(n->get_value()); };

    // Helper to check if node is a variable
    auto is_var = [&](Node *n)
    { return n && Utils::is_variable(n->get_value()); };

    // Helper to check if node is a variable or variable
    auto is_num_or_var = [&](Node *n)
    { return Utils::is_number(n->get_value()) || Utils::is_variable(n->get_value()); };

    /**
   * Rule 1
   * Expression: x * x
   * Evaluate to: x ^ 2
   * Pattern: root->value == * && left||right == variable && left->value == right->value
   */
    if (root->get_value() == "*" && is_var(left) && is_var(right) && left->get_value() == right->get_value())
    {
        return new Node("^", new Node(left->get_value()), new Node("2"));
    }

    /**
   * Rule 2
   * Expression: x^n * x^m
   * Evaluate to: x^n+m
   * Pattern: root->value == * && left->value == ^ && right->value == ^ && left->left->value == variable == right->left->value && left->right->value == constant == right->right->value
   */
    if (
        root->get_value() == "*" &&
        left && right &&
        left->get_value() == "^" &&
        right->get_value() == "^")
    {
        // expression: x^n and root = ^
        std::string left_variable = left->get_left()->get_value();

        // expression: x^m and root = ^
        std::string right_variable = right->get_left()->get_value();

        // If both variables are non-empty and same
        if (!left_variable.empty() &&
            left_variable == right_variable)
        {
            // both has a constant term
            if (is_num(left->get_right()) &&
                is_num(right->get_right()))
            {
                double power_sum = stod(left->get_right()->get_value()) + stod(right->get_right()->get_value());

                // case: power == 0
                if (power_sum == 0)
                {
                    return new Node("1");
                }

                // case: power == 1
                if (power_sum == 1)
                {
                    return new Node(left_variable);
                }

                // case: power > 1
                return new Node("^", new Node(left_variable), new Node(Utils::double_to_string(power_sum)));
            }

            // If powers are variable and number or variable and number or variable variable
            if (is_num_or_var(left->get_right()) && is_num_or_var(right->get_right()))
            {
                Node *power_node = new Node("+", new Node(left->get_right()->get_value()), new Node(right->get_right()->get_value()));
                return new Node("^", new Node(left_variable), power_node);
            }
        }
    }

    /**
   * Rule 3
   * Expression: x^n / x^m
   * Evaluate to: x^n-m
   * Pattern: root->value == / && left->value == ^ && right->value == ^
   */
    if (root->get_value() == "/" &&
        left && right &&
        left->get_value() == "^" &&
        right->get_value() == "^")
    {
        // expression: x^n and root = ^
        std::string left_variable = left->get_left()->get_value();

        // expression: x^m and root = ^
        std::string right_variable = right->get_left()->get_value();

        // If both has same variables
        if (!left_variable.empty() &&
            !right_variable.empty() &&
            left_variable == right_variable)
        {
            // If powers are constant numbers
            if (is_num(left->get_right()) && is_num(right->get_right()))
            {
                double power_sum = stod(left->get_right()->get_value()) - stod(right->get_right()->get_value());

                // case: power == 0
                if (power_sum == 0)
                {
                    return new Node("1");
                }

                // case: power == 1
                if (power_sum == 1)
                {
                    return new Node(left_variable);
                }

                // case: power > 1
                return new Node("^", new Node(left_variable), new Node(Utils::double_to_string(power_sum)));
            }

            // If powers are variable and number or variable and number or variable variable
            if (is_num_or_var(left->get_right()) && is_num_or_var(right->get_right()))
            {
                Node *power_node = new Node("-", new Node(left->get_right()->get_value()), new Node(right->get_right()->get_value()));
                return new Node("^", new Node(left_variable), power_node);
            }
        }
    }

    /**
   * Rule 4
   * Expression: x^n^m
   * Evaluate to: x^n*m
   * Pattern: root->value == ^ left->value == ^ && left->left == variable && right->value == constant
   */
    if (root->get_value() == "^" &&
        left->get_value() == "^" &&
        is_var(left->get_left()))
    {
        // If both are numbers
        if (Utils::is_number(left->get_right()->get_value()) &&
            Utils::is_number(right->get_value()))
        {
            std::string power_mul = Utils::double_to_string(stod(left->get_right()->get_value()) * stod(right->get_value()));

            // case: power == 0
            if (power_mul == "0")
            {
                return new Node("1");
            }

            // case: power == 1
            if (power_mul == "1")
            {
                return new Node(left->get_left()->get_value());
            }

            // case: power > 1
            Node *variable_node = new Node(left->get_left()->get_value());
            Node *right_node = new Node(power_mul);

            return new Node("^", variable_node, right_node);
        }

        // Both are variables or one is number and other is variable
        if (is_num_or_var(left->get_right()) && is_num_or_var(right))
        {
            Node *power_node = new Node("*", new Node(left->get_right()->get_value()), new Node(right->get_value()));
            return new Node("^", new Node(left->get_left()->get_value()), power_node);
        }
    }

    /**
   * Rule 5
   * Expression: x*x^n
   * Evaluate to: x^n+1
   * Pattern: root->value == * &&
   *            left->value == variable &&
   *            right->left->value == variable &&
   *            left->value == right->left->value &&
   *            right->right->value == constant
   */
    if (root->get_value() == "*" &&
        is_var(left) &&
        right->get_left() &&
        is_var(right->get_left()) &&
        !(left->get_value()).empty() &&
        left->get_value() == right->get_left()->get_value())
    {

        // If power is number
        if (is_num(right->get_right()))
        {

            std::string power_add = Utils::double_to_string(stod(right->get_right()->get_value()) + 1);

            // case: power == 0
            if (power_add == "0")
            {
                return new Node("1");
            }

            // case: power == 1
            if (power_add == "1")
            {
                return new Node(left->get_left()->get_value());
            }

            return new Node("^", new Node(left->get_value()), new Node(power_add));
        }

        // If power is a variable
        if (is_var(right->get_right()))
        {
            return new Node("^", new Node(left->get_value()), new Node(right->get_right()->get_value()));
        }
    }

    /**
   * Rule 6
   * Expression: x^n * x
   * Evaluate to: x^(n+1)
   * Pattern: root->value == * &&
   *           left->value == ^ &&
   *           left->left->value == variable &&
   *           right->value == same variable as left->left->value
   */
    if (root->get_value() == "*" &&
        left &&
        left->get_value() == "^" &&
        left->get_left() &&
        is_var(left->get_left()) &&
        right &&
        is_var(right) &&
        !(right->get_value()).empty() &&
        left->get_left()->get_value() == right->get_value())
    {

        // If power is number
        if (is_num(left->get_right()))
        {
            std::string power_add = Utils::double_to_string(stod(left->get_right()->get_value()) + 1);

            // case: power == 0
            if (power_add == "0")
            {
                return new Node("1");
            }

            // case: power == 1
            if (power_add == "1")
            {
                return new Node(left->get_left()->get_value());
            }

            return new Node("^", new Node(right->get_value()), new Node(power_add));
        }

        // If power is variable
        if (is_var(left->get_right()))
        {
            return new Node("^", new Node(right->get_value()), new Node(left->get_right()->get_value()));
        }
    }

    return root;
}

Node *Simplifier::combine_like_terms(Node *root)
{
    if (!root)
    {
        return nullptr;
    }

    root->set_left(combine_like_terms(root->get_left()));
    root->set_right(combine_like_terms(root->get_right()));

    Node *left = root->get_left();
    Node *right = root->get_right();

    auto get_variable = [&](Node *n)
    {
        if (!n || !n->get_left() || !n->get_right())
        {
            std::string s = "";
            return s;
        }

        if (Utils::is_variable(n->get_left()->get_value()))
        {
            return n->get_left()->get_value();
        }

        return n->get_right()->get_value();
    };

    auto get_number = [&](Node *n)
    {
        if (!n || !n->get_left() || !n->get_right())
        {
            return 0.0;
        }

        if (Utils::is_number(n->get_left()->get_value()))
        {
            return stod(n->get_left()->get_value());
        }

        return stod(n->get_right()->get_value());
    };

    auto is_valid_expression = [&](Node *l, Node *r)
    {
        bool has_l_variable = (l && l->get_left() && l->get_right()) &&
                              (Utils::is_variable(l->get_left()->get_value()) || Utils::is_variable(l->get_right()->get_value()));
        bool has_r_variable = (r && r->get_left() && r->get_right()) &&
                              (Utils::is_variable(r->get_left()->get_value()) || Utils::is_variable(r->get_right()->get_value()));

        bool has_l_number = (l && l->get_left() && l->get_right()) &&
                            (Utils::is_number(l->get_left()->get_value()) || Utils::is_number(l->get_right()->get_value()));
        bool has_r_number = (r && r->get_left() && r->get_right()) &&
                            (Utils::is_number(r->get_left()->get_value()) || Utils::is_number(r->get_right()->get_value()));

        std::string l_variable = has_l_variable ? get_variable(l) : "";
        std::string r_variable = has_r_variable ? get_variable(r) : "";

        return has_l_number && has_r_number && has_l_variable && has_r_variable && !l_variable.empty() && l_variable == r_variable;
    };

    if ((root->get_value() == "+" || root->get_value() == "-") && is_valid_expression(left, right))
    {
        std::string coefficient_result = (root->get_value() == "+") ? Utils::double_to_string(get_number(left) + get_number(right)) : Utils::double_to_string(get_number(left) - get_number(right));

        if (coefficient_result == "0")
        {
            return new Node("0");
        }

        if (coefficient_result == "1")
        {
            return new Node(get_variable(left));
        }

        return new Node("*", new Node(coefficient_result), new Node(get_variable(left)));
    }

    return root;
}

Node *Simplifier::division_simplification(Node *root)
{
    if (!root)
        return nullptr;

    root->set_left(division_simplification(root->get_left()));
    root->set_right(division_simplification(root->get_right()));

    Node *left = root->get_left();
    Node *right = root->get_right();

    if (!left || !right)
        return root;

    // Case 1: x / x → 1
    if (left->get_value() == right->get_value() && (Utils::is_variable(left->get_value()) || Utils::is_number(left->get_value())))
    {
        return new Node("1");
    }

    // Case 2: (x * y) / x → y
    if (root->get_value() == "/" && left->get_value() == "*")
    {
        Node *a = left->get_left();
        Node *b = left->get_right();

        if (a->get_value() == right->get_value())
            return b;
        if (b->get_value() == right->get_value())
            return a;
    }

    // Case 3: (x^a) / (x^b) → x^(a-b)
    if (root->get_value() == "/" &&
        left->get_value() == "^" && right->get_value() == "^")
    {
        Node *base_left = left->get_left();
        Node *base_right = right->get_left();

        if (base_left->get_value() == base_right->get_value())
        {
            Node *new_exp = new Node("-", new Node(left->get_right()->get_value()), new Node(right->get_right()->get_value()));
            return new Node("^", new Node(base_left->get_value()), new_exp);
        }
    }

    return root;
}

Node *Simplifier::constant_folding(Node *root)
{
    if (!root)
    {
        return nullptr;
    }

    root->set_left(constant_folding(root->get_left()));
    root->set_right(constant_folding(root->get_right()));

    Node *left = root->get_left();
    Node *right = root->get_right();

    // (3 * node) * 3
    if (root->get_value() == "*" && left && right && left->get_value() == "*" && Utils::is_number(right->get_value()))
    {
        // 3 * node
        if (Utils::is_number(left->get_left()->get_value()))
        {
            Node *constant_node = new Node(Utils::double_to_string(stod(right->get_value()) * stod(left->get_left()->get_value())));
            return new Node("*", constant_node, left->get_right());
        }

        // x * 3
        if (Utils::is_number(left->get_right()->get_value()))
        {
            Node *constant_node = new Node(Utils::double_to_string(stod(right->get_value()) * stod(left->get_right()->get_value())));
            return new Node("*", constant_node, left->get_right());
        }
    }

    // 3 * (3 * x)
    if (root->get_value() == "*" && left && right && right->get_value() == "*" && Utils::is_number(left->get_value()))
    {
        // 3 * x
        if (Utils::is_number(right->get_left()->get_value()))
        {
            Node *constant_node = new Node(Utils::double_to_string(stod(left->get_value()) * stod(right->get_left()->get_value())));
            return new Node("*", constant_node, right->get_right());
        }

        // x * 3
        if (Utils::is_number(right->get_right()->get_value()))
        {
            Node *constant_node = new Node(Utils::double_to_string(stod(left->get_value()) * stod(right->get_right()->get_value())));
            return new Node("*", constant_node, right->get_left());
        }
    }

    return root;
}

Node *Simplifier::advanced_simplify(Node *root)
{
    Simplifier simplify;
    int iteration = 0;
    const int MAX_ITER = 100;

    while (iteration++ < MAX_ITER)
    {
        std::string old_expression = root->to_expression();
        root = simplify.simplify(root);
        root = simplify.power_rules(root);
        root = simplify.combine_like_terms(root);
        root = simplify.division_simplification(root);
        root = simplify.constant_folding(root);

        std::string new_expression = root->to_expression();
        if (old_expression == new_expression)
        {
            break;
        }
    }

    return root;
}
