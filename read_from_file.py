def main():
    try:

        with open("testeula.ula", "r") as file:
            buffer = file.readlines()
    except FileNotFoundError:
        print("Falha ao abrir o arquivo")
        return 1  

    x, y, w = '', '', ''
    str_cmd = ''


    with open("testeula.hex", "w") as resultado:
        for buffer in buffer:
            buffer = buffer.strip()  

            if buffer == "fim.":
                print("acabou!")
                return 0

            if buffer[0] == 'X':
                x = buffer[2]

            elif buffer[0] == 'Y':
                y = buffer[2]

            elif buffer[0] == 'W':
                str_cmd = ''
                for i in range(2, len(buffer)):
                    if buffer[i] == ';':
                        break
                    str_cmd += buffer[i]
                w_map = {
                    "umL": '0',
                    "A+B": '1',
                    "copiaA": '2',
                    "nAxnB": '3',
                    "AeBn": '4',
                    "nA": '5',
                    "AenB": '6',
                    "nAonB": '7',
                    "AxB": '8',
                    "zeroL": '9',
                    "copiaB": 'A',
                    "AeB": 'B',
                    "nB": 'C',
                    "nAeBn": 'D',
                    "AoB": 'E',
                    "nAeB": 'F'
                }

                w = w_map.get(str_cmd, '?') 
                resultado.write(f"{x}{y}{w}\n")

    return 0

if __name__ == "__main__":
    main()
