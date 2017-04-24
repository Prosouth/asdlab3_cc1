//
//  LinkedList.cpp
//
//  Copyright (c) 2016 Olivier Cuisenaire. All rights reserved.
//

#include <iostream>
#include <stdexcept>
#include <cstdlib>
using namespace std;

/// Forward declaration classe
template <typename T> class LinkedList;

/// Forward declaration fonction d'affichage
template <typename T>
ostream& operator << (ostream& os, const LinkedList<T>& liste);

/// Classe de liste chainee
template <typename T> class LinkedList 
{
  friend ostream& operator << <T>(ostream& os, const LinkedList<T>& liste);
  
public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using pointer = T*;
  using const_pointer = const T*;
  
private:
   /**
   *  @brief Maillon de la chaine.
   * 
   * contient une valeur et le lien vers le maillon suivant.
   */
  struct Node {
    value_type data;
    Node* next;
    Node(const_reference data, Node* next = nullptr)
    : data(data), next(next) 
    {
      cout << "(C" << data << ") ";
    }
    Node(Node&) = delete;
    Node(Node&&) = delete;
    ~Node()
    {
      cout << "(D" << data << ") ";
    }
  };
  
private:
  /**
   *  @brief  Tete de la LinkedList
   */
  Node* head;

private:
  /**
   *  @brief Nombre d'éléments
   */
  value_type nbElements;
  
public:
  /**
   *  @brief Constructeur par défaut. Construit une LinkedList vide
   *
   */
  LinkedList() 
  { 
      head = nullptr;
  }

public:
  /**
   *  @brief Constructeur de copie
   *
   *  @param other la LinkedList à copier
   */
  LinkedList(LinkedList& other) /* ... */ 
  {
     /* ... */
  }

public:
  /**
   *  @brief Opérateur d'affectation par copie
   *
   *  @param other la LinkedList à copier
   *
   *  @return la LinkedList courante *this (par référence)
   *
   *  @remark l'opérateur doit être une no-op si other 
   *  est la LinkedList courante.
   *
   *  @remark le contenu précédent de la LinkedList courante est 
   *  effacé.
   */
  LinkedList& operator = (const LinkedList& other) 
  {
    
    return *this;
  }
  
public:
  /**
   *  @brief destructeur
   */
  ~LinkedList() 
  {
      Node* current = head;
      while(current != nullptr)
      {
          Node* next = current->next;
          delete current;
          current = next;
      }
  }
  
public:
  /**
   *  @brief nombre d'éléments stockés dans la liste
   *
   *  @return nombre d'éléments. 
   */
  size_t size() const noexcept 
  {
      return nbElements;
  }
  
public:
  /**
   *  @brief insertion d'une valeur dans un maillon en tête de liste
   *
   *  @param value la valeur à insérer
   *
   *  @exception std::bad_alloc si pas assez de mémoire, où toute autre exception lancée par la constructeur de copie de value_type
   */
  void push_front(const_reference value) 
  {
      Node* newNode;
      newNode->data = value;
      newNode->next = head;
      head = newNode;
      nbElements++;
  }
  
public:
  /**
   *  @brief accès (lecture/écriture) à la valeur en tête de LinkedList
   *
   *  @return référence à cette valeur
   *
   *  @exception std::runtime_error si la liste est vide
   */
  reference front() 
  {
      return this->at(0);
  }

  const_reference front() const 
  {
      return this->at(0);
  }

public:
  /**
   *  @brief Suppression de l'élément en tête de LinkedList
   *
   *  @exception std::runtime_error si la liste est vide
   */
  void pop_front() 
  {
      nbElements--;
  }
  
public:
  /**
   *  @brief Insertion en position quelconque
   *
   *  @param value la valeur à insérer
   *  @param pos   la position où insérer, 0 est la position en tete
   *
   *  @exception std::out_of_range("LinkedList::insert") si pos non valide
   *
   *  @exception std::bad_alloc si pas assez de mémoire, où toute autre exception lancée par la constructeur de copie de value_type
   */
  void insert(const_reference value, size_t pos) 
  {
      size_t tracker = 0;
      if(pos = 0)
      {
          push_front(value);
      }
      else
      {
          while(pos != tracker)
          {
              // on itère jusqu'au bon élément
              
          }
          Node* newNode;
          
      }
  }
  
public:
  /**
   *  @brief Acces à l'element en position quelconque
   *
   *  @param pos la position, 0 est la position en tete
   * 
   *  @exception std::out_of_range("LinkedList::at") si pos non valide
   *
   *  @return une reference a l'element correspondant dans la liste
   */
  reference at(size_t pos) 
  {
    /* ... */
    if (head == nullptr or pos > (nbElements - 1))
    {
        throw out_of_range("LinkedList::at");
    }

    Node* cur = head;
    for (size_t i = 0; i < pos; ++i)
    {
        cur = cur->next;
    }
    //return cur;
  }
  
  /**
   *  @brief Acces à l'element en position quelconque
   *
   *  @param pos la position, 0 est la position en tete
   *
   *  @exception std::out_of_range("LinkedList::at") si pos non valide
   *
   *  @return une const_reference a l'element correspondant dans la liste
   */
  const_reference at(size_t pos) const 
  {
    /* ... */
    if (head == nullptr or pos > (nbElements - 1))
    {
        throw out_of_range("LinkedList::at");
    }

    Node* cur = head;
    for (size_t i = 0; i < pos; ++i)
    {
        cur = cur->next;
        
    }
    return cur;
  }
  
public:
  /**
   *  @brief Suppression en position quelconque
   *
   *  @param pos la position, 0 est la position en tete
   *
   *  @exception std::out_of_range("LinkedList::erase") si pos non valide
   */
  void erase(size_t pos) 
  {
    if (head == nullptr or pos > (nbElements - 1))
    {
        throw out_of_range("LinkedList::erase");
    }
   /* Node* cur = this->at(pos);
    Node* prev = this->at(pos - 1);
    prev->next = cur->next;
    delete cur;*/
    nbElements--;
  }
  
public:
  /**
   *  @brief Recherche du premier élément correspondant
      à une valeur donnée dans la liste
   *
   *  @param value la valeur à chercher
   *
   *  @return la position dans la liste. -1 si la valeur
      n'est pas trouvée
   */
  size_t find(const_reference value) const noexcept 
  {
    /* ... */
  }
  
  /**
   *  @brief Tri des elements de la liste par tri fusion
   */
  void sort() 
  {
    /* ... */
  }
  
};

template <typename T>
ostream& operator << (ostream& os, const LinkedList<T>& liste) 
{
  os << liste.size() << ": ";
  auto n = liste.head;
  while (n) {
    os << n->data << " ";
    n = n->next;
  }
  return os;
}


int main() {
  
  const int N = 10;
  
  cout << "Creation d'une liste de " << N << " entiers aléatoires \n";
  LinkedList<int> liste;
  for (unsigned i = 0; i < N; ++i) 
  {
    liste.push_front(rand()%100);
  }
  cout << "\n" << liste;
  
  cout << "\nModification de l'élément en tête à 42 \n";
  liste.front() = 42;
  cout << "\n" << liste;
  
  cout << "\nModification de l'élément en position " << N/2 << " à 24 \n";
  liste.at(N/2) = 24;
  cout << "\n" << liste;

  cout << "\nSuppression de l'élément en position " << 2*N/3 << "\n";
  liste.erase(2*N/3);
  cout << "\n" << liste;
  
  cout << "\nInsertion de l'élément 421 en position 0\n";
  liste.insert(421, 0);
  cout << "\n" << liste;
  
  cout << "\nInsertion de l'élément 422 en position " << N/3 << "\n";
  liste.insert(422, N/3);
  cout << "\n" << liste;
  
  cout << "\nInsertion de l'élément 423 en dernière position\n";
  liste.insert(423, liste.size());
  cout << "\n" << liste;
 
  cout << "\nDestruction de la liste \n";
}
