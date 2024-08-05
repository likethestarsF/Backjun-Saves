# Notepad



# Git Commands
- Erase the last Commit

`git reset --soft HEAD~1`

- Change the message of the last Commit

`git commit --amend`

- Change more previous messages

`git rebase -i HEAD~3`
 
# Personal Notes.

Useful site : https://modoocode.com/




## Override operators in struct.

can be used in sorting.
https://best-coding.tistory.com/6
```
struct Data {
  int id;
  int p;
  int num;
  
  //p가 같다면 id가 작을수록. p, id this-> 생략된 것.
  bool operator < (const Data &var) const {
    if (p == var.p) 
      return id < var.id;
    return p > var.p;
  }
;
```

## Vector 101
`vector<typename> v;`

### iterators 

`v.begin()` : Pointer that directs first elem.

`v.end()` : Pointer that directs not the end of vector, but the data after the end.

`v.begin() == v.end()` It means element of vector is none.

### Elements

`v.push_back(elem)` : Add an element at the end of vector.

`v.pop_back(elem)` : Delete an element at the end of vector.

`v.insert(location, elem) : Add an element at the location where we want to add.

`v.erase(location) : Delete an element at the location where we want to remove.

## Lambda Function

### Basic Description

`[my_mod] (int v_) ->int {return v_ % my_mod;}`

`my_mod` : introducer; write external variables.

`(int v_)` : parameters; Write variables used in statement.

`->int` : return type.

`{}` : statement.

`()` can be skipped but `[]` can not.

1. `[&] () {}` : Call all external variables. (cf. `Call-by-reference`)
2. `[=] () {}` : Call all external variables as value.
3. `[=, &x, &y] () {}`
4. `[x, &y, &z] () {}`

`mutable ->type_name` : can be modify captured value.  

<details>
  
  <summary>Useful methods for the code tests</summary>
  
  ## Useful methods for code tests
  
  ### optimize iostream
  
  ```
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  // cout.tie(NULL);
  ```
  
  ### clog switch
  
  ```
  std::clog.setstate(std::ios_base::failbit);
  ```
  
</details>

<details>
  
  <summary> Modularity </summary>
  
  ## Modularity
  
  ### Function
  
  - can do overload. 
  ```
  int sum(int a, int b);
  int sum(int a, int b, int c);
  ```
  
  - Call by Value Vs. Call by Reference
  `int a` vs. `int &a`
  
  ### Template
  
  - `Any` Can be an any word: T, sometype, and so on.
  ```
  template <class Any>
  Any fn(Any a, Any b);
  ```
  
  - `template <class T, class U>` is possible. (Multiple Parameters)
  
  - Non-type template Arguments
  ```
  template <class T, int n>
  T fixed_multiply (T a) {
    return a * n;
  }
  ```
  
  `cout << fixed_multiply<int, 2>(10);`
  output : `20`
  
  ### Namespace
  
  ```
  namespace foo  { int value() {return 5;} }
  namespace bar  { int value() {return 10;} }
  ```
  `cout << foo::value();` output : `5`
  `cout << bar::value();` output : `10`
  
  using namespace is possible. e.g. `using namespace foo;`
  
  ### Structure
  
  - Basic
  ```
  struct Vector {
    int sz; 
    double *elem;
  } // two members
  ```
  
  Define a structure variable;
  ```
  Name v;
  ```
  
  Accessing a member of __.
  ```
  v.sz = s;
  ```
  
  - Pointers to structures
    - use `->` to access a member of a structure variable.
  ```
  Vector v;
  Vector *pV = &V;
  int s = 10; // or cin
  pV->elem = new double [s];
  ```
  
  ### Classes
  
  - Basic
  ```
  class class_name {
    access_specifier_1;
      member1;
    access_specifier_2;
      member2;
  } object_names;
  ```
  
  ```
  class Rectangle {
      int width, height;
    public:
      void set_values (int, int);
      int area (void);
  }
  ```
  
  - List of Access specifiers
    - private : accessible only within same class.
    - protected : accessible only within same and derived class.
    - public : free to access.
    - Default = private.
  
  - how to make Objects:
  `void Rectangle::set_values (int x, int y) { //body }`
  
  - Constructors
    - Automatically called whenever a new object of this class is created.
    - overloading possible. 
    ```
    class_name();              // default constructor
    class_name(parameters);    // constructor with parameters
    ```
  
  - Destructors
    - Automatically called when an object is destructed.
    - Execute required cleanup
  ```
  ~class_name();
  ```
  
  - Pointers to classes
    - Use `->` to access a class member
  ```
  Rectangle* rect = new Rectangle(3, 4);
  cout << rect->area(); 
  ```
  
  -Can apply template to Class
  
</details>