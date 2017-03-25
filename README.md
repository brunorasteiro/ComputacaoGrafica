# Catavento - SCC0250

## Pasta bin
* Colocar arquivos dll em bin/
* No comando make clean, deletar só o programa, pra não levar os dlls junto

# Opções de compilação
As bibliotecas que eu uso são diferentes das do Rasteiro, aí eeu botei um if pra mim no makefile e eu compilo com

    make HUGO=1

Se no de vocês não compilar, é só fazer no Makefile:

    ifdef NOME
        (mudar opcoes aqui)
    endif

com as opções que precisa e depois compilar com

	make NOME=1


## etc
Botei no .gitignore um tal .directory, se der bosta a gente tira.
