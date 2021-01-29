

void show(linked_list_t *list)
{
    linked_list_t *tmp;

    tmp = list;
    while (tmp != NULL) {
        my_putstr(tmp->data);
        my_putcahr('\n');
        tmp = tmp->next;
    }
}