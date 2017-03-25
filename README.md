# Catavento - SCC0250

## Pasta bin
* Colocar arquivos dll na pasta bin/
* No comando make clean, deletar só o programa, pra não levar os dlls junto

## Opções de compilação
As bibliotecas que eu uso são diferentes das do Rasteiro, aí eeu botei um if pra mim no makefile e eu compilo com

    make HUGO=1

Se no de vocês não compilar, é só botar no Makefile:

    ifdef NOME
        (mudar opcoes aqui)
    endif

e depois compilar com

	make NOME=1


## Gitignore
* Os arquivos da pasta bin
* Botei um tal .directory, se der bosta a gente tira.
