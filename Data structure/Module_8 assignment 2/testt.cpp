void removeDuplicates(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        Node *tmp2 = tmp;
        while (tmp2->next != NULL)
        {
            if (tmp2->next->val == tmp->val)
            {
                Node *duplicate = tmp2->next;
                tmp2->next = tmp2->next->next;
                delete duplicate;
            }
            else
            {
                tmp2 = tmp2->next;
            }
        }
        tmp = tmp->next;
    }
}