#include "node.h"
#include "differentiator.h"
#include "utils.h"

Node *Differentiator::differentiate(Node *root, const std::string &var)
{
    const std::string root_value = root->get_value();

    if (Utils::is_number(root_value))
    {
        return new Node("0");
    }

    if (Utils::is_variable(root_value))
    {
        if (root_value == var)
        {

            return new Node("1");
        }

        return new Node("0");
    }

    if (root_value == "+")
    {
        return new Node("+", differentiate(root->get_left(), var), differentiate(root->get_right(), var));
    }

    if (root_value == "-")
    {
        return new Node("-", differentiate(root->get_left(), var), differentiate(root->get_right(), var));
    }

    if (root_value == "*")
    {
        if (Utils::is_number(root->get_left()->get_value()))
        {
            return new Node("*", root->get_left(), differentiate(root->get_right(), var));
        }

        if (Utils::is_number(root->get_right()->get_value()))
        {
            return new Node("*", differentiate(root->get_left(), var), root->get_right());
        }

        Node *left = new Node("*", differentiate(root->get_left(), var), root->get_right());
        Node *right = new Node("*", root->get_left(), differentiate(root->get_right(), var));

        return new Node("+", left, right);
    }

    if (root_value == "/")
    {
        Node *numerator_left = new Node("*", differentiate(root->get_left(), var), root->get_right());
        Node *numerator_right = new Node("*", root->get_left(), differentiate(root->get_right(), var));
        Node *numerator = new Node("-", numerator_left, numerator_right);

        Node *denominator_power = new Node("2", nullptr, nullptr);
        Node *denominator = new Node("^", root->get_right(), denominator_power);

        return new Node("/", numerator, denominator);
    }

    if (root_value == "^")
    {
        if (Utils::is_variable(root->get_left()->get_value()) && root->get_left()->get_value() != var)
        {
            return new Node("0");
        }

        // If the power is a constant number and base is a variable
        if (Utils::is_number(root->get_right()->get_value()) && Utils::is_variable(root->get_left()->get_value()))
        {
            double pow_minus_1 = stod(root->get_right()->get_value()) - 1;
            std::string pow_minus_1_node_value = Utils::double_to_string(pow_minus_1);

            if (pow_minus_1 == 0)
            {
                return new Node("1");
            }

            if (pow_minus_1 == 1)
            {
                return new Node("*", root->get_right(), root->get_left());
            }

            Node *pow_minus_1_node = new Node(pow_minus_1_node_value);
            Node *power_node = new Node("^", root->get_left(), pow_minus_1_node);

            return new Node("*", root->get_right(), power_node);
        }
    }

    return new Node("0", nullptr, nullptr); // fallback
}
