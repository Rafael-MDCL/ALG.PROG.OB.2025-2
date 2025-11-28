#include "Processo.h"

Processo::Processo(int id) : pid(id) {
}

Processo::~Processo() {

}

int Processo::getPid() const {
	return pid;
}
