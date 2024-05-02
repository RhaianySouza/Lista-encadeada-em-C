
<h1>Lista Encadeada em C</h1>

Este é um programa simples em C que implementa uma lista encadeada com funcionalidades básicas, como inserção de elementos, remoção de elementos em qualquer posição, busca de elementos, impressão da lista, informação do tamanho da lista, ordenação e inversão.

<h2>Funcionalidades Implementadas:</h2>
<ul>
  <li><b>Inserção de Elementos:</b> Permite inserir elementos no início, final ou em qualquer posição específica da lista.</li>
  <li><b>Remoção de Elementos:</b> Remove um elemento da lista em uma posição específica.</li>
  <li><b>Busca de Elementos:</b> Busca um elemento específico na lista.</li>
  <li><b>Impressão da Lista:</b> Imprime todos os elementos da lista.</li>
  <li><b>Tamanho da Lista:</b> Informa o número de elementos presentes na lista.</li>
  <li><b>Ordenação:</b> Ordena os elementos da lista em ordem crescente ou decrescente.</li>
  <li><b>Inversão:</b> Inverte a ordem dos elementos na lista.</li>
</ul>
<h2>Como Usar:</h2>
<ol>
<li>Clone este repositório em sua máquina local:</li>
<code>git clone https://github.com/RhaianySouza/Lista-encadeada-em-C.git</code>
<li>Compile o programa utilizando um compilador C:</li>
<code>gcc lista_encadeada.c -o lista_encadeda</code>
<li>Após a compilação bem-sucedida, um arquivo executável chamado lista_encadeda.exe será gerado no mesmo diretório.</li>
<code>lista_encadeda.exe</code>

<h2>Exemplo de Uso:</h2>
<ul>
  <li><b>Inserir elemento no inicio da list:</b>
    <code>insereElement(20,NULL)</code> <i>Insere elemento 20 no inicio da lista</i>;
  </li>
  <li><b>Inserir elemento ao final da lista:</b>
    <code>insereElement(5,true)</code> <i>Insere elemento 5 no final da lista</i>;
  </li>
  <li><b>Inserir elemento na posição do elemento escolhido:</b>
    <code>insereElement(7,18)</code> <i>Insere elemento 7 n posição do elemendo 18 na lista</i>;
  </li>
  
  <li><b>Remove elemento no inicio da list:</b>
    <code>removeElement(NULL)</code> <i>Remove elemento 3 no inicio da lista</i>;
  </li>
  <li><b>Remove elemento ao final da lista:</b>
    <code>removeElement(-1)</code> <i>Remove elemento 14 no final da lista</i>;
  </li>
  <li><b>Remove elemento na posição do elemento escolhido:</b>
    <code>removeElement(5)</code> <i>Remove elemento 5 da lista</i>;
  </li>

  <li><b>Exibe a lista criada</b>
    <code>printList()</code>;
  </li>
  
  <li><b>Retorna o tamanho da lista criada</b>
    <code>tamanhoLista()</code>;
  </li>

  <li><b>Procurar elemento na lista criada</b>
    <code>searchElement(15)</code><i>Procura elemento 15 n lista</i>;
  </li>

  <li><b>Ordena a lista criada</b>
    <code>ordeneList(true)</code><i>Ordena a lista em recursão retorna <b>true</b> se a lista estiver ordenada</i>;
  </li>  
</ul>

<h2>Teste de execução</h2>
<table>
  <tr><td>insereElement(20,NULL);</td>  <td>Lista Criada com sucesso<br/>  Elemento 20 inserido a lista</td></tr>
  <tr><td>insereElement(5,true);</td>  <td>Elemento 5 inserido com sucesso na cauda</td></tr>
  <tr><td>insereElement(18,true);</td>  <td>Elemento 18 inserido com sucesso na cauda</td></tr>
  <tr><td>insereElement(9,true);</td>  <td>Elemento 9 inserido com sucesso na cauda</td></tr>
  <tr><td>insereElement(26,true);</td>  <td>Elemento 26 inserido com sucesso na cauda</td></tr>
  <tr><td>insereElement(3,true);</td>  <td>Elemento 3 inserido com sucesso na cauda</td></tr>
  <tr><td>insereElement(12,NULL);</td>  <td>Elemento 12 inserido a lista na cabeca</td></tr>
  <tr><td>inverterLista();</td>  <td>A lista foi invertida<br/>  Imprime Lista encadeada: 3 26 9 18 5 20 12</td></tr>
  <tr><td>insereElement(37,true);</td>  <td>Elemento 37 inserido com sucesso na cauda</td></tr>
  <tr><td>insereElement(13,true);</td>  <td>Elemento 13 inserido com sucesso na cauda</td></tr>
  <tr><td>insereElement(24,true);</td>  <td>Elemento 24 inserido com sucesso na cauda</td></tr>
  <tr><td>insereElement(7,18);</td>  <td>Elemento 7 inserido com sucesso na posicao do elemento 18</td></tr>
  <tr><td>insereElement(14,3);</td>  <td>Elemento 14 inserido com sucesso na cauda</td></tr>
  <tr><td>printList();</td>  <td>Imprime Lista encadeada: 3 26 9 7 18 5 20 12 37 13 24 14</td></tr>
  <tr><td>tamanhoLista();</td>  <td>Tamanho da lista: 12</td></tr>
  <tr><td>removeElement(NULL);</td>  <td>Elemento 3 removido com sucesso da cabeca</td></tr>
  <tr><td>printList();</td>  <td>Imprime Lista encadeada: 26 9 7 18 5 20 12 37 13 24 14</td></tr>
  <tr><td>removeElement(5);</td>  <td>Elemento 5 removido com sucesso</td></tr>
  <tr><td>printList();</td>  <td>Imprime Lista encadeada: 26 9 7 18 20 12 37 13 24 14</td></tr>
  <tr><td>removeElement(-1);</td>  <td>Elemento 14 removido com sucesso da calda</td></tr>
  <tr><td>printList();</td>  <td>Imprime Lista encadeada: 26 9 7 18 20 12 37 13 24</td></tr>
  <tr><td>tamanhoLista();</td>  <td>Tamanho da lista: 9</td></tr>
  <tr><td>ordeneList(true);</td>  <td>Lista foi ordenada com sucesso<br/>Imprime Lista encadeada: 7 9 12 13 18 20 24 26 37</td></tr>
  <tr><td>tamanhoLista();</td>  <td>Tamanho da lista: 9</td></tr>
  <tr><td>searchElement(15);</td>  <td>Elemento 15 NAO foi encontrado na lista</td></tr>
  <tr><td>searchElement(18);</td>  <td>Elemento 18 foi encontrado na lista</td></tr>
  <tr><td>inverterLista();</td>  <td>A lista foi invertida<br/>Imprime Lista encadeada: 37 26 24 20 18 13 12 9 7</td></tr>
  <tr><td>clearLista();</td>  <td></td></tr>

</table>
