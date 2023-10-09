import sys

#Condicional que valida que se ingresen exactamente 3 argumentos de entrada
if len(sys.argv) == 4:
    a = int( sys.argv[1]);
    b = int( sys.argv[2]);
    c = int( sys.argv[3]);
    def contar_primo(a,b):
        primos = 0
        if a>1:
            num = a
        else:
            num = 2
        while num<=b:
            i = 2
            esprimo = 1
            while i<num:
                if num%i==0:
                    esprimo = 0
                    break
                i+=1
            if esprimo==1:
                primos+=1
            num+=1
        return primos
    def contar_potencias(a,b,c):
        potencia = 1
        potencias = 0
        num = 0
        i = 0
        while potencia<b:
            potencia = c**i
            i+=1
            if a<=potencia<=b:
                potencias+=1
        return potencias
    if c==1:
        cantidad_primos = contar_primo(a,b)
        print("Hay ",cantidad_primos,"numeros primos en este rango")
    else:
        cantidad_potencias = contar_potencias(a,b,c)
        print("Hay",cantidad_potencias,"potencias de",c,"en este rango")
else:
    print("Debe ingresar 3 argumentos de entrada")
