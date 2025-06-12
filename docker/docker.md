# Docker

Docker empaqueta software en unidades estandarizadas llamadas contenedores que incluyen todo lo necesario para que el software se ejecute,
incluidas bibliotecas, herramientas de sistema, código y versión ejecutable. Con Docker, puede implementar y ajustar la escala de aplicaciones 
rápidamente en cualquier entorno con la certeza de saber que su código se ejecutará.


### Tipos de contenedores

Existen varios tipos de contenedores: 

1. Contendor con salida simple :  si nosotros probamos el container mas simple como el basico de **hello world**. Solo nos dara una 
salida de texto y terminara el proceso del contenedor

```bash
# Run nos permite instalar un contenedor de terceros
docker run hello-world
podman run hello world

# OUTPUT
!... Hello Podman World ...!

         .--"--.           
       / -     - \         
      / (O)   (O) \        
   ~~~| -=(,Y,)=- |         
    .---. /`  \   |~~      
 ~/  o  o \~~~~.----. ~~   
  | =(X)= |~  / (O (O) \   
   ~~~~~~~  ~| =(Y_)=-  |   
  ~~~~    ~~~|   U      |~~ 

Project:   https://github.com/containers/podman
Website:   https://podman.io
Desktop:   https://podman-desktop.io
Documents: https://docs.podman.io
YouTube:   https://youtube.com/@Podman
X/Twitter: @Podman_io
Mastodon:  @Podman_io@fosstodon.org
```
2.  Contenedor interactivo: Esto contenedores funciona diferente a los anteriores, ya que al hacer un run no nos daran una salida(output),
para que nos podamos usarlo tendremos que pasarle la **flag --it**. Esto es muy comun en imagenes de sistemas operativos

```bash
# Tenemos un contenedor de ubuntu

docker run ubuntu
podman run ubuntu 
 
# La salida de este contenedor no nos dara nada

docker run --it ubuntu 
podman run --it ubuntu 

# Con este tipo de contenedor necesitamos --it para que podamos tener acceso de al contenedor de ubuntu, nos dara accesos a una terminal de ubuntu

# Para salir solo tendriamos que poner exit

```

3. Contenedor en segundo plano: Estos contendores se ejecutan en segundo plano como un **daemon**, para que funcione la ejecucion en segundo plano
se necesita se necesita la **flag -d**. Este tipo de contenedor funciona bastante bien con base de datos y otras mas.

```bash
# Correra como un daemon pero dentro de un contenedor 
docker run -d postgres
podmna run -d postgres 
```

### Nombrando contenedores y filtrado

Normalmente cuando se tiene muchos contenedores, buscarlos es un poco confuso principalmente si no le pusiste un nombre. Para poner un nombre a un
contenedor se necesita la **flag --name** .

```bash
docker run -d --name postgres-container postgres

podman run -d --name postgres-container postgres
```

Aunque puedan tener un nombre pude ser complicado seguir buscar el contenedor para eso tenemos un filtro con la **flag -f**.

```bash
docker run -d --name postgres-container postgres

podman run -d --name postgres-container postgres

# Buscar el contenedor por un filtro

docker ps -f 'name=container_name'
podman ps -f 'name=container_name'

```
