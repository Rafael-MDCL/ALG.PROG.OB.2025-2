#include "Processo.h" // OBRIGATÓRIO: Incluir o próprio cabeçalho.

// --- DICA DE SINTAXE: O "SOBRENOME" DA FUNÇÃO (::) ---
// Na prova, se você escrever apenas "Processo(int id)", o compilador vai achar
// que é uma função solta.
// Você PRECISA usar "NomeClasse::" antes do nome do método para dizer
// "Estou implementando o método que pertence à classe Processo".
// O operador :: chama-se "Resolução de Escopo".

// --- DICA DE PERFORMANCE: LISTA DE INICIALIZAÇÃO ---
// Sintaxe: " : atributo(valor) "
// É a forma profissional de iniciar variáveis.
// Se você fizesse "pid = id;" dentro das chaves { }, o computador faria o trabalho dobrado
// (cria a variável vazia, depois apaga e põe o valor).
// Com a lista (:), a variável já nasce com o valor certo na memória.
Processo::Processo(int id) : pid(id) {
    // Corpo vazio, pois já fizemos o trabalho na linha de cima.
}

// --- DICA DE ERRO COMUM (LINKER ERROR) ---
// Mesmo que o destrutor não faça nada, ele TEM que ser implementado aqui.
// Se você apagar essas 3 linhas, vai dar aquele erro chato "LNK2019 unresolved external symbol",
// porque prometemos no .h que existia um "~Processo".
Processo::~Processo() {
    // Vazio (não alocamos memória dinâmica aqui, então nada para deletar manualmente)
}

// Implementação do Getter
// DICA: Se no .h está "const", aqui no .cpp TEM QUE ter "const" também.
// A assinatura deve ser idêntica.
int Processo::getPid() const {
    return pid;
} // Cuidado: Não precisa de ponto e vírgula ";" após fechar chaves de função em C++.

// OBSERVAÇÃO IMPORTANTE:
// Onde estão o execute(), salvar() e getTipo()?
// Resposta: Eles NÃO aparecem aqui porque são VIRTUAIS PUROS (= 0) no .h.
// Métodos abstratos não têm implementação na classe mãe.