#include<iostream>
using namespace std;

template<class T> 
struct Snode
{
    T data;
    struct Snode *next;
};
////////////////////////////////////////////////////
template<class T> 
struct Dnode
{
    T data;
    struct Dnode *next;
    struct Dnode* prev;
};
////////////////////////////////////////////////////
///////////////////////////////////////////////////
template<class T>
class SinglyLL
{
  private:
      Snode<T> * first;
      int size;
      public:
         SinglyLL();
         void InsertFirst(T);
         void InsertLast(T);
         void InsertAtPos(T,int);
         void DeleteFirst();
         void DeleteLast();
         void DeleteAtPos(int);
         void Display();
         int Count();  
};
//////////////////////////////////////////////////////
/////////////////////////////////////////////////////
template<class T>
class SinglyCL
{
  private:
    Snode<T>* first;
    Snode<T>* last;
    int size;

    public:
        SinglyCL();
        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int,int);
        void DeleteAtPos(int);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count(); 
};
///////////////////////////////////////////////////////
//////////////////////////////////////////////////////
template<class T> 
class DoublyLL
{
    private:
       Dnode<T>* first;
       Dnode<T>* last;
       int size; 
    public:   
       DoublyLL();
       void InsertFirst(int);
       void InsertLast(int);
       void InsertAtPos(int,int);
       void DeleteAtPos(int);
       void DeleteFirst();
       void DeleteLast();
       void Display();
       int Count();     
};
////////////////////////////////////////////////////
///////////////////////////////////////////////////
template<class T>
class DoublyCL
{
    private:
       Dnode<T>* first;
       Dnode<T>* last;
       int size;

    public:
       DoublyCL();
       void Display();
       int Count();
       void InsertFirst(int no);
       void InsertLast(int no);
       void InsertAtPos(int no,int ipos);
       void DeleteFirst();
       void DeleteLast();
       void DeleteAtPos(int ipos);
};

////////////////////////////////////////////////////
//Singly Linked List...
/////////////////////////////////////////////////// 

    template<class T>
    SinglyLL<T>::SinglyLL()
      {
          first=NULL;
          size=0;
      }
      template<class T> 
      void SinglyLL<T>::InsertFirst(T no)
      {
         Snode<T> * newn = new Snode<T>;

        newn->data = no;
        newn->next = NULL;

        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            newn->next = first;
            first=newn;
        }
        size++;
      }
      template<class T>
      void SinglyLL<T>::InsertLast(T no)
      {
        Snode<T>* newn = new Snode<T>;
        newn->data = no;
        newn->next = NULL;

        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            Snode<T>* temp = first;
           
            while(temp->next != NULL)
            {
                temp=temp->next;
            }
            temp->next=newn;
        }
        size++;    
      }
      template<class T>
      void SinglyLL<T>::InsertAtPos(T no,int ipos)
      {
          Snode<T>* newn = new Snode<T>;
          newn->data=no;
          newn->next=NULL;
          
          if((ipos < 1) || (ipos > size+1))  //filter
          {
              return;
          }
          if(ipos == 1)
          {
              InsertFirst(no);
          }
          else if(ipos == size+1)
          {
             InsertLast(no);
          }
          else
          {
              T i=0;
               Snode<T>* temp = first;
              for(i=1;i<ipos-1;i++)
              {
                  temp = temp->next;
              }
              newn->next=temp->next;
              temp->next=newn;
              size++; 
          }
      }
      template<class T>
      void SinglyLL<T>::DeleteFirst()
      {
          Snode<T>* temp = first;
          if(first != NULL)
          {
             first=first->next;
             delete temp;

             size--;
          }
          
      }
      template<class T>
      void SinglyLL<T>::DeleteLast()
      {
         Snode<T>* temp = first;
          if(first == NULL)
          {
              return;
          }   
          else if(first->next == NULL)
          {
              delete first;
              first = NULL;
              size--;
          }
          else
          {
           int i=0;
           while(temp->next->next != NULL)
           {
               temp = temp->next;
           }
           delete temp->next;
           temp->next=NULL;
           size--;
          }
      }

      template<class T>
      void SinglyLL<T>::DeleteAtPos(int ipos)
      {
          if((ipos < 1) || (ipos > size+1))  //filter
          {
              return;
          }
          if(ipos == 1)
          {
              DeleteFirst();
          }
          else if(ipos == size)
          {
              DeleteLast();
          }
          else
          {
              int i=0;
               Snode<T>* temp = first;
               Snode<T>* targated = NULL;
              for(i=1;i<ipos-1;i++)
              {
                  temp = temp->next;
              }
              targated=temp->next;
              temp->next=targated->next;
              delete(targated);
              size--; 
          }
      }

      template<class T>
      void SinglyLL<T>::Display()
      {
          Snode<T>* temp = first;
         while(temp != NULL)
         {
             cout<<"|"<<temp->data<<"|->";
             temp = temp->next;
         }  
         cout<<"\n";
      }
      
      template<class T>
      int SinglyLL<T>::Count()
      {
          return size;
      }
///////////////////////////////////////////////////
///////Singly circuler linked list.....
///////////////////////////////////////////////////

    template<class T> 
    SinglyCL<T>::SinglyCL()
    {
      first=NULL;
      last=NULL;
      size=0;
    }

    template<class T>
    void SinglyCL<T>::InsertFirst(int no)
    {
        Snode<T>* newn =new Snode<T>;
        newn->data=no;
        newn->next=NULL;

        if((first == NULL) &&( last == NULL))
        {
          first=newn;
          last=newn;
        }
        else
        {
          newn->next=first;
          first=newn;
        }
        last->next=first;
        size++;
    }

      template<class T>
      void SinglyCL<T>::InsertLast(int no)
      {
          Snode<T>* newn =new Snode<T>;
          newn->data=no;
          newn->next=NULL;

        if(first == NULL && last == NULL)
        {
          first=newn;
          last=newn;
        }
        else
        {
          last->next=newn;
          last=newn;

         }
        last->next=first;
        size++;
      }
      
      template<class T>
      void SinglyCL<T>::InsertAtPos(int no,int ipos)
      {          
             Snode<T>* newn=new Snode<T>;
             newn->data=no;        
             newn->next=NULL;
    
             if((ipos<1)&&(ipos>size+1))
             {
                 return;
             }
             if(ipos==1)
             {
                 InsertFirst(no);
             }
             else if(ipos==size+1)
             {
                 InsertLast(no);
             }
             else
             {
                int i=0;
                Snode<T>* temp=first;
     
                for(i=1;i<ipos-1;i++)
                {
                    temp=temp->next;
                }           
                 newn->next=temp->next;
                 temp->next=newn;
                 size++;
             }
      }

      template<class T>
      void SinglyCL<T>::DeleteFirst()
      {
        if((first==NULL)&&(last==NULL))
        {
          return;
        }
        else if(first==last)
        {
          delete first;
          first=NULL;
          last=NULL;
        }
        else
        {
           first=first->next;
           delete last->next;
           last->next=first;
         
        }
        size--;
      }

      template<class T>
      void SinglyCL<T>::DeleteLast()
      {
        Snode<T>* temp = first;
        
        if((first==NULL)&&(last==NULL))
        {
          return;
        }
        else if(first==last)
        {
          delete first;
          first=NULL;
          last=NULL;
        }
        else
        {
           while(temp->next != last)
           {
             temp=temp->next;
           }
           delete last;
           last=temp;
           last->next=first;
        }
        size--;
      }
      
       template<class T>
       void SinglyCL<T>::DeleteAtPos(int ipos) 
       {   
            if((ipos<1)&&(ipos>size))
            {
                return;
            }
            if(ipos==1)
            {
                DeleteFirst();
            }
            else if(ipos==size+1)
            {
                DeleteLast();
            }
            else
            {
               int i=0;
               Snode<T>* temp=first;
               Snode<T>* targeted =NULL; 
               for(i=1;i<ipos-1;i++)
               {
                  temp=temp->next;
               }

               targeted=temp->next;
               temp->next=temp->next->next;   
               delete targeted;
               size--;
            }
        } 
      
        template<class T>    
        void SinglyCL<T>::Display()
        {
           Snode<T>* temp = first;
           if((first == NULL)&&(last==NULL))
           {
              return;
           }
           do
           {
              cout<<"|"<<temp->data<<"|->";
              temp=temp->next;
            }while(temp != last->next);

          cout<<endl;
        }

       template<class T> 
       int SinglyCL<T>::Count()
       { 
          return size;
       }

/////////////////////////////////////////////////////////
////Doubly Linked List...
//////////////////////////////////////////////////////// 
 
 template<class T>
 DoublyLL<T>::DoublyLL()
 {
    first=NULL;
    last=NULL;
    size=0;
 }
 
 template<class T>
 void DoublyLL<T>::InsertFirst(int no)
 {
    Dnode<T>* newn =new Dnode<T>;
    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;
       
    if(first==NULL)
    {
        first=newn;
        last=newn;
    }
    else
    {
      
        newn->next=first;
        first->prev=newn;
        first=newn;
    }
    size++;
 }
 
 template<class T>
 void DoublyLL<T>::InsertLast(int no)
 { 
    Dnode<T>* newn =new Dnode<T>;
    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;
       
        if(first==NULL)
        {
            first=newn;
        }
        else
        {
            Dnode<T>* temp = first;
            while(temp->next != NULL)
            {
                temp=temp->next;
            }
            temp->next=newn;
            newn->prev=temp;
             
        }
        size++;
    }
 
    template<class T>
    void DoublyLL<T>::DeleteFirst()
    {
      Dnode<T>* temp = first;

      if(first != NULL)
      {
          first=first->next;
          delete temp;
      }
      if(first != NULL)
      {
          first->prev=NULL;
      }
      size--;
    }
 
    template<class T>
    void DoublyLL<T>::DeleteLast()
    {
        Dnode<T>* temp = first;
      if(first == NULL)
      {
          return;
      }
      else if(first->next==NULL)
      {
          delete first;
          first=NULL;
      }
      else
      {
       while(temp->next !=NULL)
       {
          temp=temp->next;
       }
       temp->prev->next=NULL;
       delete temp;
      }
      size--;
    }
 
    template<class T>
    void DoublyLL<T>::InsertAtPos(int no,int ipos)
    {
       Dnode<T>* temp =first;
       if((ipos<1)||(ipos>size+1))
       {
           return;
       }
       if(ipos==1)
       {
           InsertFirst(no);
       }
       else if(ipos==size+1)
       {
           InsertLast(no);
       }
       else
       {
           Dnode<T>* newn =new Dnode<T>;
           int i=0;
           newn->next=NULL;
           newn->prev=NULL;
           newn->data=no;

           for(i=1;i<ipos-1;i++)
           {
               temp=temp->next;
           } 

           newn->next=temp->next;
           newn->next->prev=newn;
           temp->next=newn;
           newn->prev=temp;
       }
       size++;
    }
 
    template<class T>
    void DoublyLL<T>::DeleteAtPos(int ipos)
    {
       if((ipos<1)||(ipos>size))
       {
           return;
       }
       if(ipos==1)
       {
           DeleteFirst();
       }
       else if(ipos==size)
       {
           DeleteLast();
       }
       else
       {
              Dnode<T>* temp =first;
              int i=0;
              for(i=1;i<ipos-1;i++)
              {
                 temp=temp->next;
              } 
              temp->next=temp->next->next;
              delete temp->next->prev;
              temp->next->prev=temp;
             
       }
      size--;
    }

    template<class T>
    void DoublyLL<T>::Display()
    {
        Dnode<T>* temp=first;
        while(temp != NULL)
        {
            cout<<"|"<<temp->data<<"|->";
            temp=temp->next;
        }
        cout<<"\n";
    }

    template<class T>
    int DoublyLL<T>::Count()
    {
        return size;
    }

/////////////////////////////////////////////////////////
/////Doubly Circular Linked List....
//////////////////////////////////////////////////////////

template<class T>
DoublyCL<T>::DoublyCL()
{
   first = NULL;
   last = NULL;
   size =0;
}

template<class T>
void DoublyCL<T>::InsertFirst(int no)
{
    Dnode<T>* newn = new Dnode<T>;
    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if((first == NULL)&&(last == NULL))
    {
        first=newn;
        last=newn;
    }
    else
    {
        newn->next=first;
        first->prev=newn;
        first=newn;
    }
    last->next=first;
    first->prev=last;
    size++;
}

template<class T>
void DoublyCL<T>::InsertLast(int no)
{
    Dnode<T>* newn = new Dnode<T>;
    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if((first == NULL)&&(last == NULL))
    {
        first=newn;
        last=newn;
    }
    else
    {
        last->next=newn;
        newn->prev=last;
        last=newn;
        
    }
    last->next=first;
    first->prev=last;
    size++;
}

template<class T>
void DoublyCL<T>::DeleteFirst()
{
    if((first==NULL)&&(last==NULL))
    {
        return;
    }
    else if(first==last)
    {
        delete first;
        first=NULL;
        last=NULL;
    }
    else
    {
      first=first->next;
      delete last->next;
      last->next=first;
      first->prev=last;
    }   
    size--;
}

template<class T>
void DoublyCL<T>::DeleteLast()
{
    if((first==NULL)&&(last==NULL))
    {
        return;
    }
    else if(first==last)
    {
        delete first;
        first=NULL;
        last=NULL;
    }
    else
    {
      last=last->prev;
      delete last->next;  
      last->next=first;
      first->prev=last;
    }
    size--;
}

template<class T>
void DoublyCL<T>::InsertAtPos(int no,int ipos)
{
    if((ipos<1)||(ipos>size+1))
    {
      return;
    }
    if(ipos==1)
    {
        InsertFirst(no);
    }
    else if(ipos==size+1)
    {
        InsertLast(no);
    }
    else
    {
        Dnode<T>* newn =new Dnode<T>;
        
        newn->data=no;
        newn->next=NULL;
        newn->prev=NULL;
    
        Dnode<T>* temp = first;
    
        for(int i=1;i<ipos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        newn->next->prev=newn;
        temp->next=newn;
        newn->prev=temp;
        size++;
    }
}   

template<class T>
void DoublyCL<T>::DeleteAtPos(int ipos)
{
    if((ipos<1)||(ipos>size))
    {
      return;
    }
    if(ipos==1)
    {
        DeleteFirst();
    }
    else if(ipos==size)
    {
        DeleteLast();
    }
    else
    {
        Dnode<T>* temp = first;

        for(int i=1;i<ipos-1;i++)
        {
            temp=temp->next;
        }      
        temp->next=temp->next->next;
        delete temp->next->prev;
        temp->next->prev=temp;
    }
    size--;
 
}

template<class T>
void DoublyCL<T>::Display()
{
   Dnode<T>* temp=first;

   for(int i=1;i<=size;i++)
   {
       cout<<"|"<<temp->data<<"|->";
       temp=temp->next;
   }
   cout<<"\n";
}

template<class T>
int DoublyCL<T>::Count()
{
    return size;
}

/////////////////////////////////////////////////////////
//Entry Point Funtion
//////////////////////////////////////////////////////////
int main()
{
    int iRet=0;

    SinglyLL <int>iobj;   //Obj creation in integer
    
    iobj.InsertFirst(51);
    iobj.InsertFirst(21);
    iobj.InsertFirst(11);

    iobj.InsertLast(101);
    iobj.InsertLast(111);
     
    iobj.InsertAtPos(120,3); 
    iobj.Display();

    iRet=iobj.Count();
    cout<<"Number of element are :"<<iRet<<"\n";
    
    iobj.DeleteFirst();
    iobj.Display();
    iRet=iobj.Count();
    cout<<"Number of element are :"<<iRet<<"\n";

    iobj.DeleteLast();
    iobj.Display();
    iRet=iobj.Count();
    cout<<"Number of element are :"<<iRet<<"\n";

    iobj.DeleteAtPos(3);
    iobj.Display();
    iRet=iobj.Count();
    cout<<"Number of element are :"<<iRet<<"\n";
 ///////////////////////////////////////////////////////////////////////   
    SinglyCL <char>cobj;
   
    cobj.InsertFirst('C');
    cobj.InsertFirst('B');
    cobj.InsertFirst('A');

    cobj.InsertLast('D');
    cobj.InsertLast('E');
     
    cobj.InsertAtPos('Z',4); 
    cobj.Display();

    iRet=cobj.Count();
    cout<<"Number of element are :"<<iRet<<"\n";
    
    cobj.DeleteFirst();
    cobj.Display();
    iRet=cobj.Count();
    cout<<"Number of element are :"<<iRet<<"\n";

    cobj.DeleteLast();
    cobj.Display();
    iRet=cobj.Count();
    cout<<"Number of element are :"<<iRet<<"\n";

    cobj.DeleteAtPos(3);
    cobj.Display();
    iRet=cobj.Count();
    cout<<"Number of element are :"<<iRet<<"\n";
////////////////////////////////////////////////////////////////////////////////
    DoublyLL <float>fobj;
   
    fobj.InsertFirst(30);
    fobj.InsertFirst(20);
    fobj.InsertFirst(10);

    fobj.InsertLast(40);
    fobj.InsertLast(50);
     
    fobj.InsertAtPos(45,4); 
    fobj.Display();

    iRet=fobj.Count();
    cout<<"Number of element are :"<<iRet<<"\n";
    
    fobj.DeleteFirst();
    fobj.Display();
    iRet=fobj.Count();
    cout<<"Number of element are :"<<iRet<<"\n";

    fobj.DeleteLast();
    fobj.Display();
    iRet=fobj.Count();
    cout<<"Number of element are :"<<iRet<<"\n";

    fobj.DeleteAtPos(3);
    fobj.Display();
    iRet=fobj.Count();
    cout<<"Number of element are :"<<iRet<<"\n";

    
    return 0;
}