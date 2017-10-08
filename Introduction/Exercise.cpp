
/*Exercise 1.1.a*/
typedef struct tree* T_tree;
struct tree {T_tree left ; T_tree right ; String key};

T_tree Tree(T_tree l, String k, T_tree r){
  T_tree t=check_malloc(sizeof(*t));
  t->left=l; t->key=k; t->right=r;
  return t;
}

T_tree insert(String key, T_tree t){
  if(t==NULL)return Tree(NULL,key,NULL);
  else if(strcmp(key,t->key)<0)
    return Tree(insert(key,t->left),t->key,t->right);
  else if(strcmp(key,t->key)>0)
    return Tree(t->left,t->key,insert(key,t->right));
  else return Tree(t->left,key,t->right);
}

bool number(String key,T_tree t){
  if(t==NULL)return FALSE;
  else if(strcmp(key,t->key)>0)
    return number(key,t->right);
  else if(strcmp(key,t->key)<0)
    return number(key,t->left);
  else return TRUE;
}

/*Exercise 1.1.b*/

/*Exercise 1.1.c.(a)*/
/*
t->s->p->i->f->b
*/

/*Exercise 1.1.c.(a)*/
/*
a
 ->b
	->c
	   ->d
		  ->e
			 ->f
				->g
				   ->h
				      ->i
*/

/*Exercise 1.1.c.(d)*/