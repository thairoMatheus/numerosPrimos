import argparse

def primo(n):
    if n == 0 or n == 1:
        return False
    for i in range(2,int(n**0.5+1)):
        if (n%i == 0):
            return False
    return True
    
if __name__ == "__main__":
    parser = argparse.ArgumentParser()

    parser.add_argument("--N",default=1000,type=int,
                        help="Quantidade de números primos a ser mostrada ou armazenada")
    parser.add_argument("--saveFile",default=False,type=bool,
                        help="Opção que escolhe entre salvar ou mostrar os números encontrados")
    parser.add_argument("--o",default="a.txt",type=str,
                        help="Nome do arquivo a ser escrito caso --saveFile=True")
    parser.add_argument("--onlyOdd",default=False,type=bool,
                        help="Opção que define se o 2 deve aparecer ou não")

    f=None
    args = parser.parse_args()
    i = 0 # número de números já encontrados
    n = 3 # variável que serve de número atual para os testes

    if args.saveFile:
        f = open(args.o,"w+")
        f.write("{")
    numP = 30
    j = 0

    if args.N >= 1:
        if (not args.onlyOdd):
            j = 1
            i = 1
            if args.saveFile:
                f.write("2, ")
            else:
                print("2, ",end="")

    while i < args.N-1:
        if primo(n):
            i = i + 1
            if j < numP-1:
                if args.saveFile:
                    f.write("{}, ".format(n))
                else:
                    print(n,end=", ")
                j=j+1
            else:
                if args.saveFile:
                    f.write("{},\n".format(n))
                else:
                    print("{},".format(n))
                j=0
        n = n + 2

    while (not primo(n)):
        n = n+2
    if args.saveFile:
        f.write("{} }};\n".format(n))
        f.close()
    else:
        print("{}".format(n))       
        