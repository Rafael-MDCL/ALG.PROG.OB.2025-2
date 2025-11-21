#include "ReadingProcess.h"
#include "FilaDeProcessos.h" // OBRIGATÓRIO: Para usar "fila.adicionar()"
#include "ComputingProcess.h" // OBRIGATÓRIO: Para fazer "new ComputingProcess()"

using namespace std;

// --- DICA DE PROVA: INICIALIZANDO REFERÊNCIAS ---
// Você TEM que inicializar a referência 'fila' na lista de inicialização (:).
// Se tentar fazer "fila = filaDoSistema;" dentro das chaves { }, vai dar erro.
// Motivo: Uma referência é um apelido que nasce grudado. Não dá pra criar o apelido
// vazio e grudar depois.
ReadingProcess::ReadingProcess(int pid, FilaDeProcessos& filaDoSistema)
    : Processo(pid), fila(filaDoSistema) {
}

ReadingProcess::~ReadingProcess() {};

int ReadingProcess::getTipo() const {
    return 3; // Código 3 para Leitura
}

// No salvar, o ReadingProcess só precisa guardar seu próprio ID.
// Ele não guarda o conteúdo do arquivo que ele lê (isso seria redundante).
void ReadingProcess::salvar(std::ofstream& arquivo) const {
    arquivo << pid << std::endl;
}

void ReadingProcess::execute() {
    float n1, n2;
    char op;

    // 1. ABRIR PARA LEITURA (ifstream)
    ifstream arquivoLeitura("computation.txt");

    // --- DICA DE LÓGICA: LOOP DE LEITURA ---
    // "while (arquivo >> n1 >> op >> n2)"
    // Isso significa: Tente ler 3 coisas. Se conseguir ler todas, entra no loop.
    // Se o arquivo acabar ou tiver erro de formatação, o loop para sozinho.
    while (arquivoLeitura >> n1 >> op >> n2) {

        // --- CRIAÇÃO DINÂMICA ---
        // Criamos um novo ComputingProcess com os dados lidos.
        // Usamos PID 0 (ou negativo) pois são processos automáticos,
        // não foram criados pelo menu do usuário.
        fila.adicionar(new ComputingProcess(0, n1, op, n2));
    }

    // IMPORTANTE: Fechar o modo leitura antes de abrir o modo escrita/limpeza.
    arquivoLeitura.close();

    // --- TRUQUE PARA LIMPAR ARQUIVO ---
    // Ao abrir um "ofstream" SEM a flag "ios::app", o comportamento padrão
    // é "Truncate" (apagar tudo e começar do zero).
    // Abrimos e fechamos imediatamente só para zerar o arquivo.
    ofstream arquivoLimpeza("computation.txt");
    arquivoLimpeza.close();
}