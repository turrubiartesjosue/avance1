#include <iostream>
#include <fstream>

using namespace std;

struct usuario {
	char nombre[50];
	char email[50];
	char comercio[50];
	usuario* sig;
};

struct cliente {
	char nombreCliente[50];
	int monto;
	int subtotal;
	int descuento;
	int total;
	cliente* sig2;
};

struct promocion {
	char nombreProm[50];
	int montoProm;
	int porcentajeProm;
	char estatusProm[50];
	promocion* sig3;
};

struct consumo {
	char clienteCons[50];
	int montoCons;
	int subtotalCons;
	int descuentoCons;
	int totalCons;
	consumo* sig4;
};

usuario* inicio, * aux = nullptr;
cliente* inicio2, * aux2 = nullptr;
promocion* inicio3, * aux3 = nullptr;
consumo* inicio4, * aux4 = nullptr;

void altaUsuario(usuario* nuevo);
void modificarUsuario(char nomUsa[50]);
void leerBinarioUsuario();
void escribirBinarioUsuario();

void altaCliente(cliente* nuevo2);
void modificarCliente(char nomCli[50]);
void eliminarCliente(char nomCli[50]);
void listaCliente();
void leerBinarioCliente();
void escribirBinarioCliente();
void iniciarsesion();
void altaPromocion(promocion* nuevo3);
void listaProm();
void leerBinarioProm();
void escribirBinarioPromocion();

void altaConsumo(consumo* nuevo4);
void listaCons();
void leerBinarioConsumo();
void escribirBinarioConsumo();



void iniciarsesion() {


}


int main() {

	string user = "", pass = "";
	cout << "ingresa tu nombre de usuario :" << endl;
	cin >> user;
	cout << "ingresa contraseña :" << endl;
	cin >> pass;
	if (user == "jtturbo " && pass == "buenas45")
	{
		cout << "bienvenido";
	}
	else {
		cout << "usuario no encontrado";
	}

	int op = 0;
	char nomUsa[] = { 0 };
	char nomCli[] = { 0 };
	char nomProm[] = { 0 };
	char nomCons[] = { 0 };

	usuario* nodoUsa = new usuario;
	cliente* nodoCli = new cliente;
	promocion* nodoProm = new promocion;
	consumo* nodoCons = new consumo;

	leerBinarioUsuario();
	leerBinarioCliente();
	leerBinarioProm();
	leerBinarioConsumo();

	
		

	do {
		system("cls");
		cout << "::::Menu::::" << endl;
		cout << "1.- Alta de usuario" << endl;
		cout << "2.- Modificar usuario" << endl;
		cout << "3.- Alta de clientes" << endl;
		cout << "4.- Modificar clientes" << endl;
		cout << "5.- Baja de clientes" << endl;
		cout << "6.- Listado de clientes" << endl;
		cout << "7.- Alta de promociones" << endl;
		cout << "8.- Lista de promociones" << endl;
		cout << "9.- Alta de consumo" << endl;
		cout << "10.- Lista de consumo" << endl;
		cin >> op;
		cin.ignore();

		if (op == 1) {
			cout << "Nombre de usuario: " << endl;
			cin.getline(nodoUsa->nombre, 50);
			cout << "Correo de usuario: " << endl;
			cin.getline(nodoUsa->email, 50);
			cout << "Comercio de usario: " << endl;
			cin.getline(nodoUsa->comercio, 50);
			altaUsuario(nodoUsa);
			op = 0;
		}
		else if (op == 2) {
			cout << "Nombre de usuario a modificar: " << endl;
			cin.getline(nomUsa, 50);
			modificarUsuario(nomUsa);
			cin.ignore();
			op = 0;
		}
		else if (op == 3) {
			cout << "Nombre de cliente: " << endl;
			cin.getline(nodoCli->nombreCliente, 50);
			cout << "El monto del cliente: " << endl;
			cin >> nodoCli->monto;
			cin.ignore();
			cout << "El subtotal del cliente: " << endl;
			cin >> nodoCli->subtotal;
			cin.ignore();
			cout << "El Descuento del cliente: " << endl;
			cin >> nodoCli->descuento;
			cin.ignore();
			cout << "El total del cliente: " << endl;
			cin >> nodoCli->total;
			cin.ignore();
			op = 0;
		}
		else if (op == 4) {
			cout << "Nombre de cliente a modificar: " << endl;
			cin.getline(nomCli, 50);
			modificarCliente(nomCli);
			cin.ignore();
			op = 0;
		}
		else if (op == 5) {
			cout << "Nombre de cliente a eliminar: " << endl;
			cin.getline(nomCli, 50);
			eliminarCliente(nomCli);
			op = 0;
		}
		else if (op == 6) {
			listaCliente();
			cin.ignore();
			op = 0;
		}
		else if (op == 7) {
			cout << "Nombre de la promocion: " << endl;
			cin.getline(nodoProm->nombreProm, 50);
			cout << "El monto de la promocion: " << endl;
			cin >> nodoProm->montoProm;
			cin.ignore();
			cout << "El porcentaje de descuento de la promocion: " << endl;
			cin >> nodoProm->porcentajeProm;
			cin.ignore();
			cout << "Estatus de la promocion: " << endl;
			cin.getline(nodoProm->estatusProm, 50);
			altaPromocion(nodoProm);
			op = 0;
		}
		else if (op == 8) {
			listaProm();
			cin.ignore();
			op = 0;
		}
		else if (op == 9) {
			cout << "Nombre del cliente: " << endl;
			cin.getline(nodoCons->clienteCons, 50);
			cout << "El monto del consumo: " << endl;
			cin >> nodoCons->montoCons;
			cin.ignore();
			cout << "Subtotal del consumo: " << endl;
			cin >> nodoCons->subtotalCons;
			cin.ignore();
			cout << "Descuento del consumo: " << endl;
			cin >> nodoCons->descuentoCons;
			cin.ignore();
			cout << "Total del consumo: " << endl;
			cin >> nodoCons->totalCons;
			cin.ignore();
			altaConsumo(nodoCons);
			op = 0;
		}
		else if (op == 10) {
			listaCons();
			cin.ignore();
			op = 0;
		}

	} while (op < 1 || op > 11);

	escribirBinarioUsuario();
	escribirBinarioCliente();
	escribirBinarioPromocion();
	escribirBinarioConsumo();

	system("PAUSE");
	return 0;
}

void altaUsuario(usuario* nuevo) {
	if (inicio == nullptr) {
		inicio = new usuario;
		aux = inicio;

		strcpy_s(aux->nombre, nuevo->nombre);
		strcpy_s(aux->email, nuevo->email);
		strcpy_s(aux->comercio, nuevo->comercio);
		aux->sig = nullptr;
	}
	else {
		aux = inicio;
		while (aux->sig != nullptr)
		{
			aux = aux->sig;
		}

		aux->sig = new usuario;

		aux = aux->sig;

		strcpy_s(aux->nombre, nuevo->nombre);
		strcpy_s(aux->email, nuevo->email);
		strcpy_s(aux->comercio, nuevo->comercio);

		aux->sig = nullptr;
	}
}
void modificarUsuario(char usuBuscar[50]) {
	aux = inicio;
	char newUsu[50];
	if (aux == nullptr) {
		cout << "La lista esta vacia. Agregue un usuario" << endl;
	}
	else {
		while (aux != nullptr && strcmp(aux->nombre, usuBuscar) != 0) {
			aux = aux->sig;
		}
		if (aux == nullptr) {
			cout << "Usuario no encontrado" << endl;
		}
		else {
			cout << "::::Usuario encontrado:::: " << endl;
			cout << "Nombre del usuario: " << aux->nombre << endl;
			cout << endl;

			cout << "Nuevo nombre del usuario: " << endl;
			cin.getline(newUsu, 50);
			strcpy_s(aux->nombre, newUsu);
			cout << endl;
			cout << "::::Usuario modificado:::: " << endl;
		}
	}
	system("PAUSE");
}

void altaCliente(cliente* nuevo2) {

	if (inicio2 == nullptr) {
		inicio2 = new cliente;
		aux2 = inicio2;

		aux2->monto = nuevo2->monto;
		strcpy_s(aux2->nombreCliente, nuevo2->nombreCliente);
		aux2->subtotal = nuevo2->subtotal;
		aux2->descuento = nuevo2->descuento;
		aux2->total = nuevo2->total;
		aux2->sig2 = nullptr;
	}
	else {
		aux2 = inicio2;
		while (aux2->sig2 != nullptr) {
			aux2 = aux2->sig2;
		}

		aux2->sig2 = new cliente;

		aux2 = aux2->sig2;

		strcpy_s(aux2->nombreCliente, nuevo2->nombreCliente);
		aux2->monto = nuevo2->monto;
		aux2->subtotal = nuevo2->subtotal;
		aux2->descuento = nuevo2->descuento;
		aux2->total = nuevo2->total;

		aux2->sig2 = nullptr;
	}
}
void modificarCliente(char cliBuscar[50]) {
	aux2 = inicio2;
	char newCli[50];
	if (aux2 == nullptr) {
		cout << "La lista esta vacia. Agregue un cliente" << endl;
	}
	else {
		while (aux2 != nullptr && strcmp(aux2->nombreCliente, cliBuscar) != 0) {
			aux2 = aux2->sig2;
		}
		if (aux2 == nullptr) {
			cout << "Cliente no encontrado" << endl;
		}
		else {
			cout << "::::Cliente encontrado:::: " << endl;
			cout << "Nombre del cliente: " << aux2->nombreCliente << endl;
			cout << endl;

			cout << "Nuevo nombre del cliente: " << endl;
			cin.getline(newCli, 50);
			strcpy_s(aux2->nombreCliente, newCli);
			cout << "endl";
			cout << "::::Cliente modificado:::: " << endl;
		}
	}
	system("PAUSE");
}
void eliminarCliente(char cliEliminar[50]) {
	aux2 = inicio2;
	cliente* anterior = nullptr;
	if (aux2 == nullptr)
	{
		cout << "La lista esta vacia. Agregue clientes" << endl;
	}
	else {
		while (aux != nullptr && strcmp(aux2->nombreCliente, cliEliminar) != 0) {
			anterior = aux2;
			aux2 = aux2->sig2;
		}
		if (aux == nullptr) {
			cout << "Usuario no encontrado" << endl;
		}
		else if (aux2 == inicio2) {
			cout << "::::Usuario encontrado:::: " << endl;
			cout << "Nombre del usuario: " << aux2->nombreCliente << endl;
			cout << endl;

			inicio2 = aux2->sig2;
			delete aux2;

			aux2 = inicio2;

			cout << "::::Cliente eliminado:::: " << endl;
		}
		else {
			cout << "::::Cliente encontrado:::: " << endl;
			cout << "Nombre del cliente: " << aux2->nombreCliente << endl;
			cout << endl;

			anterior->sig2 = aux2->sig2;

			delete aux2;

			aux2 = inicio2;

			cout << "::::Cliente eliminado:::: " << endl;

		}
	}
	system("PAUSE");
}
void listaCliente() {
	system("cls");
	if (inicio2 == nullptr) {

		cout << endl;
		cout << "La lista esta vacia. Agregue clientes";

	}
	else {
		aux2 = inicio2;

		while (aux2 != nullptr)
		{
			cout << "Cliente: " << aux2->nombreCliente << endl;
			cout << "Monto: " << aux2->monto << endl;
			cout << "Subtotal: " << aux2->subtotal << endl;
			cout << "Descuento: " << aux2->descuento << endl;
			cout << "Total: " << aux2->total << endl;
			aux2 = aux2->sig2;
		}
	}
}
void altaPromocion(promocion* nuevo3) {
	if (inicio3 == nullptr) {
		inicio3 = new promocion;
		aux3 = inicio3;

		strcpy_s(aux3->nombreProm, nuevo3->nombreProm);
		aux3->montoProm = nuevo3->montoProm;
		aux3->porcentajeProm = nuevo3->porcentajeProm;
		strcpy_s(aux3->estatusProm, nuevo3->estatusProm);
		aux3->sig3 = nullptr;
	}
	else {
		aux3 = inicio3;
		while (aux3->sig3 != nullptr) {
			aux3 = aux3->sig3;
		}

		aux3->sig3 = new promocion;

		aux3 = aux3->sig3;

		strcpy_s(aux3->nombreProm, nuevo3->nombreProm);
		aux3->montoProm = nuevo3->montoProm;
		aux3->porcentajeProm = nuevo3->porcentajeProm;
		strcpy_s(aux3->estatusProm, nuevo3->estatusProm);

		aux3->sig3 = nullptr;
	}
}
void listaProm() {
	system("cls");
	if (inicio3 == nullptr) {

		cout << endl;
		cout << "La lista esta vacia. Agregue promociones";

	}
	else {
		aux3 = inicio3;

		while (aux3 != nullptr)
		{
			cout << "Nombre: " << aux3->nombreProm << endl;
			cout << "Monto: " << aux3->montoProm << endl;
			cout << "Porcentaje de descuento: " << aux3->porcentajeProm << endl;
			cout << "Estatus: " << aux3->estatusProm << endl;
			aux3 = aux3->sig3;
		}
	}
}
void altaConsumo(consumo* nuevo4) {
	if (inicio4 == nullptr) {
		inicio4 = new consumo;
		aux4 = inicio4;

		strcpy_s(aux4->clienteCons, nuevo4->clienteCons);
		aux4->montoCons = nuevo4->montoCons;
		aux4->subtotalCons = nuevo4->subtotalCons;
		aux4->descuentoCons = nuevo4->descuentoCons;
		aux4->totalCons = nuevo4->totalCons;
		aux4->sig4 = nullptr;
	}
	else {
		aux4 = inicio4;
		while (aux4->sig4 != nullptr) {
			aux4 = aux4->sig4;
		}

		aux4->sig4 = new consumo;

		aux4 = aux4->sig4;

		strcpy_s(aux4->clienteCons, nuevo4->clienteCons);
		aux4->montoCons = nuevo4->montoCons;
		aux4->subtotalCons = nuevo4->subtotalCons;
		aux4->descuentoCons = nuevo4->descuentoCons;
		aux4->totalCons = nuevo4->totalCons;
		aux4->sig4 = nullptr;

		aux4->sig4 = nullptr;
	}
}
void listaCons() {
	system("cls");
	if (inicio4 == nullptr) {

		cout << endl;
		cout << "La lista esta vacia. Agregue consumos";

	}
	else {
		aux4 = inicio4;

		while (aux4 != nullptr)
		{
			cout << "Nombre del cliente: " << aux4->clienteCons << endl;
			cout << "Monto: " << aux4->montoCons << endl;
			cout << "subtotal: " << aux4->subtotalCons << endl;
			cout << "Descuento: " << aux4->descuentoCons << endl;
			cout << "Total: " << aux4->totalCons << endl;
			aux4 = aux4->sig4;
		}
	}
}



void leerBinarioConsumo() {
	ifstream archivoConsumo;
	archivoConsumo.open("consumo.txt", ios::in | ios::binary);

	aux4 = inicio4;
	if (archivoConsumo.is_open()) {

		consumo* consumoLeido = new consumo;

		while (!archivoConsumo.read((char*)consumoLeido, sizeof(consumo)).eof()) {

			while (aux4 != nullptr && aux4->sig4 != nullptr)
			{
				aux4 = aux4->sig4;
			}
			if (aux4 == nullptr) {
				inicio4 = consumoLeido;
				inicio4->sig4 = nullptr;
				aux4 = inicio4;
			}
			else {
				aux4->sig4 = consumoLeido;
				aux4->sig4->sig4 = nullptr;
			}

			consumoLeido = new consumo;
		}
		archivoConsumo.close();
	}
	else {
		cout << "No es posible abrir el archivo.";
		system("PAUSE");
	}
}
void escribirBinarioConsumo() {
	aux4 = inicio4;

	ofstream escribirConsumo;
	escribirConsumo.open("consumo.txt", ios::out | ios::binary | ios::trunc);

	if (escribirConsumo.is_open()) {
		while (aux4 != nullptr)
		{
			escribirConsumo.write((char*)aux4, sizeof(consumo));
			aux4 = aux4->sig4;
		}

		escribirConsumo.close();
	}
	else
	{
		cout << "No se pudo abrir el archivo.";
		system("PAUSE");
	}
}

void leerBinarioUsuario() {

	ifstream archivoUsuario;
	archivoUsuario.open("usuario.txt", ios::in | ios::binary);

	aux = inicio;
	if (archivoUsuario.is_open()) {

		usuario* usuarioLeido = new usuario;

		while (!archivoUsuario.read((char*)usuarioLeido, sizeof(usuario)).eof()) {

			while (aux != nullptr && aux->sig != nullptr)
			{
				aux = aux->sig;
			}
			if (aux == nullptr) {
				inicio = usuarioLeido;
				inicio->sig = nullptr;
				aux = inicio;
			}
			else {
				aux->sig = usuarioLeido;
				aux->sig->sig = nullptr;
			}

			usuarioLeido = new usuario;
		}
		archivoUsuario.close();
	}
	else {
		cout << "No es posible abrir el archivo.";
		system("PAUSE");
	}
	

}
void escribirBinarioUsuario() {

	aux = inicio;
	ofstream escribirUsuario;
	escribirUsuario.open("usuario.txt", ios::out | ios::binary | ios::trunc);

	if (escribirUsuario.is_open()) {
		while (aux != nullptr)
		{
			escribirUsuario.write((char*)aux, sizeof(usuario));
			aux = aux->sig;
		}

		escribirUsuario.close();
	}
	else
	{
		cout << "No se pudo abrir el archivo.";
		system("PAUSE");
	}
}

void leerBinarioCliente() {

	ifstream archivoCliente;
	archivoCliente.open("cliente.txt", ios::in | ios::binary);

	aux2 = inicio2;
	if (archivoCliente.is_open()) {

		cliente* clienteLeido = new cliente;

		while (!archivoCliente.read((char*)clienteLeido, sizeof(cliente)).eof()) {

			while (aux2 != nullptr && aux2->sig2 != nullptr)
			{
				aux2 = aux2->sig2;
			}
			if (aux2 == nullptr) {
				inicio2 = clienteLeido;
				inicio2->sig2 = nullptr;
				aux2 = inicio2;
			}
			else {
				aux2->sig2 = clienteLeido;
				aux2->sig2->sig2 = nullptr;
			}

			clienteLeido = new cliente;
		}
		archivoCliente.close();
	}
	else {
		cout << "No es posible abrir el archivo.";
		system("PAUSE");
	}
}
void escribirBinarioCliente() {
	aux2 = inicio2;

	ofstream escribirCliente;
	escribirCliente.open("cliente.txt", ios::out | ios::binary | ios::trunc);

	if (escribirCliente.is_open()) {
		while (aux2 != nullptr)
		{
			escribirCliente.write((char*)aux2, sizeof(cliente));
			aux2 = aux2->sig2;
		}

		escribirCliente.close();
	}
	else
	{
		cout << "No se pudo abrir el archivo.";
		system("PAUSE");
	}
}

void leerBinarioProm() {
	ifstream archivoPromocion;
	archivoPromocion.open("promocion.txt", ios::in | ios::binary);

	aux3 = inicio3;
	if (archivoPromocion.is_open()) {

		promocion* promocionLeida = new promocion;

		while (!archivoPromocion.read((char*)promocionLeida, sizeof(promocion)).eof()) {

			while (aux3 != nullptr && aux3->sig3 != nullptr)
			{
				aux3 = aux3->sig3;
			}
			if (aux3 == nullptr) {
				inicio3 = promocionLeida;
				inicio3->sig3 = nullptr;
				aux3 = inicio3;
			}
			else {
				aux3->sig3 = promocionLeida;
				aux3->sig3->sig3 = nullptr;
			}

			promocionLeida = new promocion;
		}
		archivoPromocion.close();
	}
	else {
		cout << "No es posible abrir el archivo.";
		system("PAUSE");
	}
}
void escribirBinarioPromocion() {
	aux3 = inicio3;

	ofstream escribirPromocion;
	escribirPromocion.open("promocion.txt", ios::out | ios::binary | ios::trunc);

	if (escribirPromocion.is_open()) {
		while (aux3 != nullptr)
		{
			escribirPromocion.write((char*)aux3, sizeof(promocion));
			aux3 = aux3->sig3;
		}

		escribirPromocion.close();
	}
	else
	{
		cout << "No se pudo abrir el archivo.";
		system("PAUSE");
	}
}

