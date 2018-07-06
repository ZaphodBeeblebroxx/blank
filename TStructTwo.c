#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct profile_tree_node
{

  char *fName;
  char *lName;
  int age;
  struct profile_tree_node *parent;
  struct profile_tree_node *children[10];
  int childCount;
};
struct profile_tree_node *get_par(struct profile_tree_node *any)
{

  struct profile_tree_node *result;
  result = any;
  if (result->parent != NULL)
  {
    result = get_par(any->parent);
    return result;
  }
  else
  {

    return result;
  }
}
int nodecmp(struct profile_tree_node *here, struct profile_tree_node *there)
{
  int returner = 0;

  if (strcmp(here->fName, there->fName) != 0)
  {
    returner++;
  }
  if (strcmp(here->lName, there->lName) != 0)
  {
    returner++;
  }
  if (here->age != there->age)
  {
    returner++;
  }

  return returner;
}

struct profile_tree_node *search_name(char *name, int option,
                                      struct profile_tree_node *base)
{

  struct profile_tree_node *result;
  char *desName;
  desName;

  if (option == 1)
  {

    desName = base->lName;
  }

  if (option == 0)
  {

    desName = base->fName;
  }

  if (strcmp(desName, name) == 0)
  {
    return base;
  }

  if (base->childCount != 0)
  {

    for (int i = 0; i < (*base).childCount; i++)
    {
      result = search_name(name, option, base->children[i]);
      if (result == NULL)
      {
        
        continue;
      }
      else
      {

        return result;
      }
    }
    // NO PARENTS.. NO CHILDREN HAVE THE RESULT

    return NULL;
  }
}

struct profile_tree_node *get_by_name(char *name, int option,
                                      struct profile_tree_node *base)
{

  struct profile_tree_node *result;

  // get highest parent

  result = get_par(base);

  // search downwards

  result = search_name(name, option, result);

  return result;
}

struct profile_tree_node *createTreePointer(char *fName, char *lName, int age)
{

  struct profile_tree_node *node;

  node = malloc(sizeof(struct profile_tree_node));
  node->fName = malloc(sizeof(char) * 50);
  node->lName = malloc(sizeof(char) * 50);

  strcpy((*node).fName, fName);

  strcpy((*node).lName, lName);
  node->age = age;
  (*node).childCount = 0;
  (*node).parent = NULL;
  for (int i = 0; i < 10; i++)
  {
    (*node).children[i] = NULL;
  }

  return node;
}

void childTo(struct profile_tree_node *parent,
             struct profile_tree_node *child)
{
  int i;

  i = parent->childCount;
  parent->children[i] = child;
  child->parent = parent;
  //     int *y;
  //    y = malloc(sizeof(int));
  parent->childCount++;

  //       *y = *((*parent).childCount)+1;
  //     *((*parent).childCount) = *y;
}

void childMultiple(struct profile_tree_node *parent,
                   struct profile_tree_node *children[], int count)
{
  for (int i = 0; i < count; i++)
  {
    if (i>parent->childCount)
    {
      break;
    }
    childTo(parent, children[i]);
  }
}
int index_getter(struct profile_tree_node *child,
                 struct profile_tree_node *parent)
{

  int *u;
  u = malloc(sizeof(int));

  for (*u = 0; *u < parent->childCount; *u = *u + 1)
  {

    if (nodecmp(parent->children[*u], child) == 0)
    {

      return *u;
    }
    else
    {
      continue;
    }
  }
  return *u;
}
void fill_array(int index, int childCount,
                struct profile_tree_node *siblings[])
{

  // if there is something above the target...
  if (siblings[index + 1] != NULL)
  {

    //...and also if the one two above the target is empty
    if (siblings[index] + 2 == NULL)
    {
      siblings[index] = siblings[index + 1];
      siblings[index + 1] = NULL;
    }
    else // ... or if there is something two above the target
    {
      struct profile_tree_node *previo;
      previo = siblings[index];

      siblings[index] = siblings[index + 1];
      index = index + 1;

      // for each of the things above the target while it isn't null ahead,
      // move shift each of them down
      for (int i = index + 1; i < childCount; i++)
      {

        if (siblings[i + 1] == NULL)
        {
        }
        siblings[i + 1] = siblings[i];

        previo = siblings[i];
      }
    }

    siblings[index] = siblings[index + 1];

    siblings[index + 1] = NULL;
  }
  else

  {

    siblings[index] = NULL;
  }
}

void recursive_print(struct profile_tree_node *node, int distance)
{

  if (node->childCount != 0)
  {

    for (int i = 0; i < node->childCount; i++)
    {

      recursive_print(node->children[i]);
    }
    printf("\n%s\n", node->fName);
  }else{
       printf("\n%s\n", node->fName);
  }
  }
  void print_tree(struct profile_tree_node *base)
{

  struct profile_tree_node *root;

  root = get_par(base);

  recursive_print(root);
}
  void recur_deleter(struct profile_tree_node * node)
  {

    if (node->childCount != 0)
    {

      for (int i = 0; i < node->childCount; i++)
      {

        recur_deleter(node->children[i]);
        



      }
      
    }
   

      node->parent->childCount = node->parent->childCount - 1;
      int temp = index_getter(node, node->parent);

      fill_array(temp, node->parent->childCount, node->parent->children);
      free(node);
 
  }
  void name_deleter(char *name, int option, struct profile_tree_node *base)
  {
    recur_deleter(get_by_name(name, option, base));
  }

  void test_one()
  {

    struct profile_tree_node *root = createTreePointer("John", "Smith", 76);
    struct profile_tree_node *john[10];
    struct profile_tree_node *jerry[10];
    john[0] = malloc(sizeof(struct profile_tree_node) * 10);
    jerry[0] = malloc(sizeof(struct profile_tree_node) * 10);
    struct profile_tree_node *one_one = createTreePointer("Thurman", "Smith", 34);
    struct profile_tree_node *one_two = createTreePointer("Jerry", "Smith", 46);
    struct profile_tree_node *one_three =
        createTreePointer("Rachel", "Smith", 46);
    john[0] = one_one;
    john[1] = one_two;
    john[2] = one_three;
    childMultiple(root, john, 3);

    struct profile_tree_node *two_one = createTreePointer("Jean", "Westwood", 16);
    jerry[0] = two_one;

    struct profile_tree_node *two_two = createTreePointer("John", "Smith", 26);
    jerry[1] = two_two;
    childMultiple(one_two, jerry, 2);

    struct profile_tree_node *searchTest;
    for (int i = 0; i < (root->childCount); i++)
    {
      printf("\n%s\n", root->children[i]->fName);

      char *thur[30];
      thur[0] = malloc(sizeof(char) * 30);
      *thur = "Jerry";
      searchTest = get_by_name(*thur, 0, two_two);
    }

    printf("\n\n%s\n\n", searchTest->fName);
  }

  void test_two()
  {

    struct profile_tree_node *root = createTreePointer("John", "Smith", 76);
    struct profile_tree_node *john[10];
    struct profile_tree_node *jerry[10];
    printf("one\n");
    john[0] = malloc(sizeof(struct profile_tree_node) * 10);
    jerry[0] = malloc(sizeof(struct profile_tree_node) * 10);
    struct profile_tree_node *one_one = createTreePointer("Thurman", "Smith", 34);
    struct profile_tree_node *one_two = createTreePointer("Jerry", "Smith", 46);
    printf("two\n");
    struct profile_tree_node *one_three =
        createTreePointer("Rachel", "Smith", 46);
    john[0] = one_one;
    john[1] = one_two;
       printf("three\n");
    john[2] = one_three;
    childMultiple(root, john, 3);
       printf("four\n");

    struct profile_tree_node *two_one = createTreePointer("Jean", "Westwood", 16);
    jerry[0] = two_one;

    struct profile_tree_node *two_two = createTreePointer("Jack", "Smith", 26);
    jerry[1] = two_two;
    childMultiple(one_two, jerry, 2);

    struct profile_tree_node *searchTest;

    char *thur[30];
    thur[0] = malloc(sizeof(char) * 30);
    *thur = "Jerry";
    print_tree(two_two);
    printf("\n\n\n");
    name_deleter(*thur, 0, two_two);

    print_tree(two_two);
  }

  int main()
  {
    test_two();
    return 0;
  }
