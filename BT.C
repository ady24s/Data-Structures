{
node * temp, *newnode;
char ans, c,choice;
do
{
cout << “Enter the element to be attached “;
c=getchar();
newnode = new node(c); //call constructor of node class
if(root==NULL)
root = newnode;
else
{
temp = root;
while(1)
{
cout <<“Left or right (l/r) of %d?” << temp->data;
cin>>ans;
if(ans == ‘l’)
if(temp->left == NULL)
{ temp->left = newnode; break; }
else
temp = temp->left;
else
if(temp->right == NULL)
{ temp->right = newnode; break; }
else
temp = temp->right;
}
}
cout<<“Any more nodes: ”;
cin>>choice ;
} while ( choice == ‘y’) ||(choice==’Y’);
}