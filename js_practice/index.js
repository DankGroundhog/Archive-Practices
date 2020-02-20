console.log('Hello world, this is a test.');
//console.log = print = cout

let temp_var = "Some value goes here";
// Puntos y coma como C++ son requisito en algunas secciones
// 'let' se usa para hacer variables, tambien se usa 'var' y se hace igual que C++
console.log(temp_var);

let Person = {
    name: undefined,
    age: undefined,
    isApproved: false
        // Person Object
};

function cambio() {
    alert('Undiste el boton');
}

// console.warn("Solo es un warning chiquito");



/*
    Documentation string como C++.

    Primitie data types:
    1 - Strings (Escape sequences iguales que Python y C++)
    2 - Number
    3 - Bool (true/false --> minuscula)
    4 - undefined ('undefined')
    5 - Null (used when explicitly want to clear the value of a variable)

    Objects:
    Ex. let Person = {
        name: "John",
        age: 21
    };     
    - Se puede usar dor operator Person.name
    - Se puede usar bracket operator Person["name"]

    Arrays:
    - Syntax igual que Python
    - Son dinamicos de por si y el largo del array puede cambiar whenever
    - ".shift()" saca el primer item, ".pop()" saca el ultimo
    - ".unshift()" agrega por el principio, ".push()" por el final

    Functions:

    - Se define una funcion con el keyword "function" seguido por el nombre de la funcion
    - No llevan punto y coma al final como los objetos
    - 'return' se usa aqui tambien

    For loops:
    - for (*let or var* *variable* 'of' *iterable*)

*/