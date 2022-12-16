# My Developer Journey

My personal knowledge base. It's a bunch of QAs, documentation &amp; code snippets that I gathered along the way of becoming a software engineer.

## Angular

### Angular - General  

- *What are directives in Angular?*  

### Angular - Routing

### Angular - Forms

- *How do template based forms differ from reactive forms?*  
- *How do template forms work in angular?*  
  - A form is composed of a `<form>` tag that contains divs of the **form-group** class. Each form group contains a `<label>` and a `<input>` tag. Finally you have a submit button
  
  ```html
  <form>
    <div class="form-group">
        <label></label>
        <input>
    </div>
    <button type="submit"></button>
  </form>
  ```

  - A form should have a  **template ref** variable that so we can refer to the form as a whole.  We assign this variable the value **ngForm** which is a directive [See Official Angular Documentation on Directives](https://angular.io/guide/attribute-directives)

  ```html
  <form #formName="ngForm">
  ```

  - Every `<input>`tag has to have a name attribute which is used as the field's key on submission.  
  
  ```html
  <input name="fieldName">
  ```  

  - Input tags need an event listener, ngModel. It's used to encapsulate other event such as key presses and focus, blur, etc (anything that has to do with input control).  We give it a placeholder value that we'll use later on in the form data.  
  
  ```html
  <input (ngModel)="model.fieldName">
  ```  

  - To submit a form you need to add a (ngSubmit) event listener to the `<form>` tag. We assign it to the method that we want to call when submitting the form and pass the **template ref variable** value of the form to it (it's an object container key value pairs of the fields and the submitted values).

  ```html
  <form (ngSubmit)=methodName(templateRefName.value)>

  ```

  - The final product would look something like the following (for an example login form):

  ```html
  <form #loginForm="ngForm" (ngSubmit)="login(loginForm.value)">
    <div class="form-group">
        <label for="emailAddress">Email</label>
        <input name="emailAddress" type="email" class="form-control" id="emailAddress">
    </div>
    <div class="form-group">
        <label for="password">Password</label>
        <input name="password" type="password" class="form-control" id="password">
    </div>
    <button type="submit" class="btn btn-primary"></button>
  </form>

  ```

<p align="left" style="padding-left:40px">
    <img width= 500px src="assets/angular/angular-1.png">
</p>
