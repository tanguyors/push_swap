#include "pushswap.h"

// Vérifier si un string représente un nombre valide (avec ft_isdigit de la libft)
int is_valid_number(const char *str)
{
    int i = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;

    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);  // Retourne 0 si ce n'est pas un nombre
        i++;
    }

    return (1);  // Retourne 1 si valide
}

// Vérifier si une valeur est déjà présente dans STACK_A
int is_duplicate(t_stack *stack, int value)
{
    t_node *current = stack->top;

    while (current != NULL)
    {
        if (current->value == value)
            return (1);  // Doublon trouvé
        current = current->next;
    }

    return (0);  // Pas de doublon
}

// Fonction principale pour initialiser STACK_A avec les arguments
int init_stack_with_args(t_stack *stack_a, int argc, char **argv)
{
    int i = 1;
    long value;

    // Parcourir les arguments et initialiser STACK_A
    while (i < argc)
    {
        if (!is_valid_number(argv[i]))  // Vérification si l'argument est un nombre valide
        {
            ft_putstr_fd("Error: Invalid number\n", 2);
            return (0);
        }

        value = ft_atoi(argv[i]);  // Utilisation de ft_atoi de ta libft

        // Vérifier si la valeur est dans les bornes d'un int
        if (value < INT_MIN || value > INT_MAX)
        {
            ft_putstr_fd("Error: Number out of range\n", 2);
            return (0);
        }

        // Vérifier les doublons dans STACK_A
        if (is_duplicate(stack_a, (int)value))
        {
            ft_putstr_fd("Error: Duplicate value\n", 2);
            return (0);
        }

        // Utilisation de ta fonction `init_stack` pour ajouter l'élément
        if (!push(stack_a, (int)value))  // Assumant que init_stack insère un élément dans la pile
        {
            ft_putstr_fd("Error: Unable to initialize stack\n", 2);
            return (0);
        }

        i++;
    }

    return (1);  // Retourne 1 si tout est correct
}
