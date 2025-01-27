#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*int main() {

	char *data = "Hello, World!";
	t_list *node = ft_lstnew(data);
	if (node == NULL)
		printf("Failed to create node\n");
	printf("Content: %s\n", (char *)node->content);
	if (node->next == NULL) {
		printf("Next: NULL\n");
	} else {
		printf("Next: Not NULL\n");
	}

		free(node);

	return (0);
}*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*int main() {
	t_list *head = NULL; // Start with an empty list

	// Create new nodes
	t_list *node1 = ft_lstnew("Node 1");
	t_list *node2 = ft_lstnew("Node 2");
	t_list *node3 = ft_lstnew("Node 3");

	// Add the first node
	ft_lstadd_front(&head, node1); // head now points to Node 1

	// Add the second node at the front
	ft_lstadd_front(&head, node2); // head now points to Node 2

	// Add the third node at the front
	ft_lstadd_front(&head, node3); // head now points to Node 3

	// Print the list
	t_list *current = head; // Start from the head
	while (current != NULL) {
		printf("Content: %s\n", (char *)current->content);
		current = current->next; // Move to the next node
	}

	// Free memory (important!)
	current = head;
	while (current != NULL) {
		t_list *temp = current;
		current = current->next;
		free(temp); // Free each node
	}

	return (0);
}*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*buffer;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	buffer = *lst;
	while (buffer->next != NULL)
		buffer = buffer->next;
	buffer->next = new;
}
/*int main() {
	t_list *head = NULL; // Start with an empty list

	// Create new nodes
	t_list *node1 = ft_lstnew("Node 1");
	t_list *node2 = ft_lstnew("Node 2");
	t_list *node3 = ft_lstnew("Node 3");

	ft_lstadd_back(&head, node1);
	ft_lstadd_back(&head, node2);
	ft_lstadd_back(&head, node3);


	t_list *current = head;
	while (current != NULL) {
		printf("Content: %s\n", (char *)current->content);
		current = current->next;
	}
	current = head;
	while (current != NULL) {
		t_list *temp = current;
		current = current->next;
		free(temp);
	}

	return (0);
}*/
int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*buffer;

	if (lst == NULL)
		return (0);
	i = 0;
	buffer = lst;
	while (buffer != NULL)
	{
		buffer = buffer->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*buffer;

	if (lst == NULL)
		return (NULL);
	buffer = lst;
	while (buffer->next != NULL)
		buffer = buffer->next;
	return (buffer);
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buffer;

	while (*lst != NULL)
	{
		buffer = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		(*lst) = buffer;
	}
	*lst = NULL;
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*node;

	new_list = NULL;
	while (lst != NULL)
	{
		node = ft_lstnew(f(lst->content));
		if (node == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, node);
		lst = lst->next;
	}
	return (new_list);
}
void	print_content(void *content)
{
	printf("%s\n", (char *)content);
}
/*void	*transform_content(void *content)
{
	char	*new_content;

	new_content = strdup((char *)content);
	if (!new_content)
		return (NULL);
	for (int i = 0; new_content[i]; i++)
	{
		new_content[i] = new_content[i] - 32;
	}
	return ((void *)new_content);
}*/
/*void	delete_content(void *content)
{
	free(content);
}*/
/*int main() {
	t_list *node1 = ft_lstnew(strdup("hello"));
	t_list *node2 = ft_lstnew(strdup("world"));
	t_list *node3 = ft_lstnew(strdup("banana"));
	node1->next = node2;
	node2->next = node3;

	printf("Original list:\n");
	ft_lstiter(node1, print_content);


	t_list *new_list = ft_lstmap(node1, transform_content, delete_content);

	printf("\nTransformed list:\n");
	ft_lstiter(new_list, print_content);

	ft_lstclear(&node1, delete_content);
	ft_lstclear(&new_list, delete_content);

	return (0);
}*/
