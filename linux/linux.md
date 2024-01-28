# Curso de Linux

### Comandos
* * * * * * * * Listar las redes wifi cercanas
```bash
nmcli dev wifi 
```
* Listar las fuentes del sistema 
```bash
fc-list
```


### Instalar zsh y "configurarlo"

Primero tenemos que instalar zsh

```bash
sudo apt install zsh

sudo pacman -S zsh
```

Despues de instalar zsh, tenemos que hacer que zsh sea nuestra terminal por defecto y esto se logra con el siguieten comando

```bash
usermod --shell /usr/bin/zsh {nombre de usuario}
```

Una vez listo, el interprete zsh va a estar sin configurar, para configurarlo vamos a editar el archivo **.zshrc**. Este se encuentra en`~/.zshrc`, la configuracion la vamos a sacar del siguiente link.
<a href="https://s4vitar.github.io/bspwm-configuration-files/#">Este es link para configuracion de zsh</a>

En este archivo .zshrc tenemo que modificar unas lineas, porque tienen el path del que hizo la configuracion, la linea que tenemos que modificar es la siguiente:

```bash
source /home/{nombreDelUsuario}/powerlevel10k/powerlevel10k.zsh-theme
```

Una vez que modificamos esa linea, tenemos que instalar los siguientes paquetes.

```bash
sudo apt install zsh-syntax-highlighting

sudo pacman -S zsh-syntax-highlighting
```

Este paquete nos da resaltado en la terminal, este plugin ya esta agregado en el `.zshrc` que descargamos, pero si no lo esta, tenemos que agregar la siguiente linea en el archivo `.zshrc`

```bash
source /usr/share/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh
```

Tambien necesitamos otro paquete que es el siguiente:

```bash
sudo apt install zsh-autosuggestions

sudo pacman -S zsh-autosuggestions
```

Este paquete nos da sugerencias en la terminal, este plugin ya esta agregado en el `.zshrc` que descargamos, pero si no lo esta, tenemos que agregar la siguiente linea en el archivo `.zshrc`

```bash
source /usr/share/zsh-autosuggestions/zsh-autosuggestions.zsh
```

Ya por ultimo necesitas instalr lsd y bat, esto debiado a que zsh no reconoce lsni cat, estos dos son alternativas **"mejores"** y se instalan de la siguiente manera.

```bash

sudo apt install lsd bat

```

### PowerLevel10k zsh

Para instalar powerlevel10k tenemos que clonar el repositorio de github que es el siguiente: <a href="https://github.com/romkatv/powerlevel10k#installation">repo</a>

```bash
git clone --depth=1 https://github.com/romkatv/powerlevel10k.git ~/powerlevel10k
echo 'source ~/powerlevel10k/powerlevel10k.zsh-theme' >>~/.zshrc
```

Una vez clonado,cuando abramos una terminal nos va a aparecer una configuracion para elegir, elegimos la que mas nos guste y listo. Una vez que terminemos de configurar, tenemos que cerrar la terminal y volver a abrirla para que se apliquen los cambios.

Podemos anadir mas configuracion si nos metemos al archivo `.p10k.zsh` que se encuentra en `~/.p10k.zsh`. Podemos anadir lo siguiente:

```bash
command_execution_time
context
```

Uno de estas configuraciones nos ayuda para ver cuanto tiempo se tardo en ejecutar un comando y la otra nos ayuda a ver en que carpeta estamos.

##### Instalar poweLevel10k en el usuario root

Una vez hecho todo lo anterior, tenemos que hacer lo mismo pero en el usuario root, para eso tenemos que hacer un enlace simbolico del archivo `.zshrc` que esta en el usuario normal al usuario root, para eso tenemos que hacer lo siguiente:

```bash
ls -s -f /home/{nombreDeUsuario}/.zshrc /root/.zshrc
```

Una vez hecho el enalce simbolico tenemos que volver a clonar el repo que clonamos anteriormente, pero esta vez en el usuario root, para eso tenemos que hacer lo siguiente:

```bash
cd
git clone --depth=1 https://github.com/romkatv/powerlevel10k.git ~/powerlevel10k
echo 'source ~/powerlevel10k/powerlevel10k.zsh-theme' >>~/.zshrc
```

Una vez hecho esto tenemos que borrar una configuraciones que se repiten en el archivo `.zshrc` que se encuentra en el usuario root, para eso tenemos que borrar las siguientes lineas si se repiten y si no se repiten **no se borra**:

```bash
source ~/powerlevel10k/powerlevel10k.zsh-theme
```

Ya que hicimos lo anterior, salimos del usuario root y volvemos a entrar y listo, ya tenemos powerlevel10k en el usuario root.

Tambien si queremos podemos anadir mas configuracion en el archivo `.p10k.zsh` que se encuentra en el usuario root. Recomiendo anadir un icon de **_nerdfonts_** para el usuario root, para esto buscamos `ROOT_TEMPLATE` y anadimos el iconito

## Anadir repositorios de terceros y cambiar los repositorios por defecto

Primero debemos saber en donde podemos modificar los repositorios de donde descargamos software y este se encuetra el la siguiente ruta: `/etc/apt/`. Dentro
tendremos diferentes ficheros y directorios, los que a nosotros nos interesan son el fichero `sources.list` y el directorio `sources.list.d/`.

#### Cambiar repo por defecto

Primero lo que haremos es modificar el `sources.list` y lo haremos para cambiar los repositorios que tiene por defecto, estos repositorios
llegan a estar incompletos o aputan hacia los repositorios del cd de instalacion, asi que los vamos a cambiar por los de la siguiente url(los que estan en esta url funcionan de manera diferente)
<a href="https://gist.github.com/hakerdefo/5e1f51fa93ff37871b9ff738b05ba30f">debian bookworm repository(asi lo buscamos en internet)</a>. Una vez dentro de la url
copiaremos lo primero que nos aparece y lo pegaremos en el `sources.list` y antes de hacer esto comentaremos los otros repositorios que no nos interesan
para que no de conflicto. Una vez hecho esto usaremos el siguiente comando para actualizar nuestra lista de repositorios:

```bash
sudo apt update
```

Con esto hecho ya habremos cambiado los repositorios. Tambien seria recomendable tener un resplado de nuestro `sources.list` y lo hacemos creando un fichero
que tengo lo mismo y el mismo nombre pero que cambie su extencion con .bak para que el sistema no lo lea y solo lo tengamos para respaldo.

## Anadir repositorios de terceros

## Formatear una memoria en linux

PRIMERO VAMOS A LISTAR LOS DISPOSITIVOS CONECTADOS CON EL SIGUENTE COMAND: `lsblk`. Una vez listados vamos a desmontar el sistema de ficheros que tengo el
dispositivo que querermos formatear y para eso ocupamos el siguente comando:

```bash
sudo umount /dev/{elnombreDeTuDispositivo}
```

Normalmente todos los dispositivos conectados estan ubicados en /dev. A continuacion tendremos que montar otro sistema de ficheros que en este caso sera fat32

```bash
sudo mkfs.vfat -F 32 -n {nombreQueLeVayasADar} /dev/{nombreDispositivo}
```

mkfs significa makefilesystem y vfat es para especificar el formato que es fat y ya despues la bandera -F 32 significa que sera FAT32 y -n es para darle el
nombre a la memoria

## Trabajar con php en linux

Instalar primero php:

```bash
❯ sudo apt install php php-cli php-common php-curl php-json php-mbstring php-mysql php-xml php-gd                                                           ─╯
```

Segundo instalar el composer con curl:

```bash
curl -sS https://getcomposer.org/installer  -o compose.php

```

Tercero ejecutar el script que nombramos compose.php

```bash
sudo php compose.php --install-dir="/usr/local/bin" --filename="composer"
```

Ejecutamos el script y especificamos en donde lo vamos a tener ubicado con `install-dir`y como se va a llamar con el `filename` en este caso se llama composer`

## Instalar mysql

Primero tendriamos que agregar el repositorio de mysql y eso e hace buscando `mysql apt` pero te paso el link
<a href="https://dev.mysql.com/downloads/repo/apt/">Aqui esta el .deb que nos da el repositorio</a> y despues de que tengamos el .deb lo instalamos con el siguiente comando:

```bash
sudo dpkg -i {.debMysql}
```

Recomiendo que te guies por la documentacion de mysql para que no tengas problemas<a href='https://dev.mysql.com/doc/mysql-apt-repo-quick-guide/en/#apt-repo-fresh-install'>Aca esta</a>, una vez instalado el .deb tenemos que actualizar la lista de repositorios con el siguiente comando:

```bash
sudo apt update
```

Una vez actualizada la lista de repositorios tenemos que instalar mysql con el siguiente comando:

```bash
sudo apt install mysql-server
```

Mysql es un daemon y si quieres lo puedes deshabilitar con el siguiente comando:

```bash
sudo systemctl disable mysql
# Y cuando lo quieras ocupar lo habilitas con el siguiente comando
sudo systemctl start mysql
```
