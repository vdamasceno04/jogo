#include "ListaEntidades.h"

ListaEntidades::ListaEntidades():objLE(){}

ListaEntidades::~ListaEntidades(){}

void ListaEntidades::addEntidade(Entidades::Entidade* entidade) { objLE.push(entidade); }

void ListaEntidades::removeEntidade(Entidades::Entidade* entidade) { objLE.pop(entidade);}

