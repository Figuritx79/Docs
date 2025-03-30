# Laravel documentacion

Estas es un documentacion personal para entender de mejor manera el framework laravel.

## Que es?
Primero tenemos que preguntarnos, que es laravel?. Laravel es un framework fullstack para el desarrollo web, el cual usa php como lenguaje.

Laravel es un framewokr fullstack ya que te permite crear apliaciones tanto front como back, usando su motor de plantillas llamado **blade** o hacer uso de los framworks mas famosos framworks de JavaScript(vue,react,etc). Tambien se usa bastante en el backend para crear **APIS**, ya que te ofrece un conjunto de herramientas bastante robustas. 

## Primero pasos(First steps)

Primero tenemos que saber que laravel es un framework basado en el uso de configuracion las cuales vienen en un archivo **.env**. En este archivo vamos a tener diferentes configuraciones desde el nombre del proyecto hasta el puerto,contrasena de la base de datos. En pocas palabras es nuestro archivo para configurar nuestro entorno de desarrollo con el framework.

### Configurar una base de datos 
Para configurar los puertos, contrasenas, usuario de la base de datos, tenemos en el archivo **.env**. En el cual tenemos lo siguiente.

```bash
DB_CONNECTION=pgsql
DB_HOST=127.0.0.1
DB_PORT=5432
DB_DATABASE=laravel_learn
DB_USERNAME=postgres
DB_PASSWORD=Cancerber@200505
```
Como podemos observar tenemos el provedor de base de datos que pueden ser varios como **SQLITE,POSTGRES,MYSQL,REDIS,MONGO,ETC**
y despues tenemos lo basico, usuario,puerto,contra,base de datos,etc. Cuando quieras cambiar el provedor o alguna cosa de la base de datos se hace con las lineas de arriba.

### Configuracion inicial

En laravel los archivos de configuracion, se encuentran en la carpeta **/config**. La ventaja es laravel como tal no necesita mucha configuracion posterior de crear la app pero lo podemos modificar dependiendo de caso de uso. 

En la carpeta /config vamos a encontrar un archivo ```app.php``` este te puede llegar a interasar para cambiar region, zona horaria, etc

## Cicl'','aplicacion de **laravel** el servidor http nginx o apache reedireccionara la pagina al  archivo ```index.php```(se encuentra en /public).

Este archivo no cuenta con mucho contenido pero lo principal que hace es generar el **autoloader de composer**(**NO TODAVIA QUE ES**), tambien llamada a bootstap/app.php este archivito genera una instancia de la aplicacion. Practicamente como en contexto a la aplicacion.

### Htpp/console kernel



## Encriptacion y desencriptacion del .env 
Laravel te permite encriptar el archivo .env con el siguiente comando:
```bash
php artisan env:encrypt
# Este comando tiene muchos parametros para usar. Para saber cuales hay corre:
php artisan env:encrypt --help
```
Cuando ejecutes el comando te va a preguntar si quieres que te genere una key o si tienes una. La opcion depende de ti.
Para encriptar el .env laravel usa el algoritmo AES-256-CBC por defecto(puedes cambiarlo, pero revisa la doc para ver que algoritmos soporta) 

Ahora veamos com se  desencripta el archivo

```bash
php artisan env:decrypt

# Este comando tiene muchos parametros para usar. Para saber cuales hay corre:
php artisan env:decrypt --help
```
## Leer valores de configuracion y Set 
Para poder acceder a los diferentes valores que tiene los archivos que se encuentran en el directorio de **config/**, puedes hacer lo siguiente:

```php
# Primera forma
$value = Config::get('app.timezone');
# Segunda forma 
$value = config('app.timezone');
# Regre el valor por defecto, si el valor de la configuracion no existe
$value = config('app.timezone', 'Asia/Seoul');
```

Para dar valores a las diferentes configuracion en tiempos de ejecucion, puedes usar:
```php
Config::set('app.timezone', 'America/Chicago');
 
config(['app.timezone' => 'America/Chicago']);
#IMPORTANTE NO USAR LA FUNCION ENV(), EN ARCHIVOS FUERA DE CONFIG
# SI QUIERES ACCEDER A LOS VALORES UTILZA LAS FUNCIONES DE ARRIBA
```

## Cambiar prefijo api en un api Laravel
Para cambiar el prefijo ve al archivo ```bootstrap/app.php``:

```php
->withRouting(
    api: __DIR__.'/../routes/api.php',
    apiPrefix: 'api/admin',
    // ...
)
```

## Rutas personalizadas
En algunos casos vas a querer tener un archivo diferete para tus rutas que no sean ```web.php``` ```api.php```, para eso necesitas ir a ```bootstrap/app.php``` para usar la clausula **then**:
```php
use Illuminate\Support\Facades\Route;
 
->withRouting(
    web: __DIR__.'/../routes/web.php',
    commands: __DIR__.'/../routes/console.php',
    health: '/up',
    // Aca tendrias que definir el otro archivo con su prefijo, el nombre, la ruta y el middleware
    then: function () {
        Route::middleware('api')
            ->prefix('webhooks')
            ->name('webhooks.')
            ->group(base_path('routes/webhooks.php'));
    },
)
```

Tambien laravel te permite gestionar las ruta de forma manual con el uso de la clausula **using**:
```php
// NOTA 
// Siempre que uses este vas a tener q  ue declarar todos los archivos de ruta manualmente. Haciendolo tu
use Illuminate\Support\Facades\Route;
 
->withRouting(
    commands: __DIR__.'/../routes/console.php',
    using: function () {
        Route::middleware('api')
            ->prefix('api')
            ->group(base_path('routes/api.php'));
 
        Route::middleware('web')
            ->group(base_path('routes/web.php'));
    },
)
```

## Expresiones regulares en los parametros de las rutas

Si tus rutas al momento de recibir un parametro necesitas hacer valdaciones con  expresiones regulares, laravel te ofrece una forma muy sencilla con su funcion ```where()```
```php

Route::get('/user/{name}', function (string $name) {
    // ...
})->where('name', '[A-Za-z]+');
 
Route::get('/user/{id}', function (string $id) {
    // ...
})->where('id', '[0-9]+');
 
Route::get('/user/{id}/{name}', function (string $id, string $name) {
    // ...
})->where(['id' => '[0-9]+', 'name' => '[a-z]+']);
```

Tambien ofrece funciones de ayuda(helper functions) las cuales te simplifican el uso de las expresiones regulares:
```php
Route::get('/user/{id}/{name}', function (string $id, string $name) {
    // ...
})->whereNumber('id')->whereAlpha('name');
 
Route::get('/user/{name}', function (string $name) {
    // ...
})->whereAlphaNumeric('name');
 
Route::get('/user/{id}', function (string $id) {
    // ...
})->whereUuid('id');
 
Route::get('/user/{id}', function (string $id) {
    // ...
})->whereUlid('id');
 
Route::get('/category/{category}', function (string $category) {
    // ...
})->whereIn('category', ['movie', 'song', 'painting']);
 
Route::get('/category/{category}', function (string $category) {
    // ...
})->whereIn('category', CategoryEnum::cases());
```
## Middlewares globlales

En laravel puedes definir **middlewares** de forma global atraves del fichero ```bootstrap/app.php```. En este fichero tendremos pondremos los middlewares que van a ser globales para toda la aplicacion

```php
use App\Http\Middleware\EnsureTokenIsValid;
->withMiddleware(function (Middleware $middleware) {
    //  Anade al final de la lista global de los middlewares
     $middleware->append(EnsureTokenIsValid::class);
    //  Anade al inicio de la lista global de los middleares
     $middleware->prepend(EnsureTokenIsValid::class);

    // Anade un middleware global en el contexto de las rutas web
    $middleware->web(append: [
        EnsureUserIsSubscribed::class,
    ]);
 
    // Anade un middleware global en el contexto de las rutas api
    $middleware->api(prepend: [
        EnsureTokenIsValid::class,
    ]);
})
```
Las rutas web y api tiene sus propios middleware por defecto y si quieremos anadir alguno se hace como en el ejemplo de arriba
