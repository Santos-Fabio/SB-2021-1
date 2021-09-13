#include <bits/stdc++.h>
using namespace std;

//Variaveis Globais
int ACC=INT_MIN,PC=0;
typedef struct instr{
    string nome;
    int opcode;
    int tamanho;
}instrucao_def;
map<int,int> Data; //endereço:vlr
string Arquivo_de_entrada_str;
vector<int> Arquivo_de_entrada;



//Funcoes
string Ler_entrada(char *argumento_main){//Ler arquivo de entrada e por em uma string ignorando comentario
    FILE *pFile;
    char c;
    string Arquivo;
    pFile = fopen(argumento_main,"r");
    if(pFile == NULL){
        perror("Arquivo Inexistente");
    }else{
        while(c!=EOF){
            c = fgetc(pFile);
            c = towupper(c);
            if(c!=EOF)
            Arquivo.push_back(c);
        }
    }
    fclose(pFile);
    return Arquivo;
}

int conversor_str_int(string str){
    int casas_decimais=0,n=0,aux=0;
    for(int i=0; i<str.size();i++){
        if(str[i]>='0' && str[i]<='9'){
            casas_decimais++;
        }
    }
    if(casas_decimais==1){
        for(int i=0; i<str.size();i++){
            if(str[i]>='0' && str[i]<='9'){
                n=str[i]-'0';
            }
        }
    }else{
        for(int i=str.size()-1; i>=0;i--){
            if(str[i]>='0' && str[i]<='9'){
                n+=(str[i]-'0')*pow(10,aux);
                aux++;
            }
        }
    }
    return n;
}



void set_data(){
    int opcode;
    for(int i=0; i<Arquivo_de_entrada.size();i+=2){//Colocando o PC no inicio do data section
        PC++;
        PC++;
        if(Arquivo_de_entrada[i]==9){//COPY
            PC++;
            i++;
        }else if(Arquivo_de_entrada[i]==14){
            PC--;
            break;
        }
    }
    vector<int>::iterator it=find(Arquivo_de_entrada.begin(),Arquivo_de_entrada.end(),14);
    ++it;//iterator tbm está no inicio do data_sec
    for(it; it!=Arquivo_de_entrada.end();++it){
        Data[PC]=*it;//add o valor no data_section a lista
        PC++;
    }
    PC=0;
}

void simulador(){
    int STOP=0,instrucao=0,input;
    while(!STOP){
        cout<<ACC<<"PC:"<<PC<<endl;
        switch(Arquivo_de_entrada[PC]){
            case 1://ADD
                PC++;
                ACC+=Data[Arquivo_de_entrada[PC]];
                PC++;
            break;

            case 2://SUB
                PC++;
                ACC-=Data[Arquivo_de_entrada[PC]];
                PC++;
            break;

            case 3://MUL
                PC++;
                ACC*=Data[Arquivo_de_entrada[PC]];
                PC++;
            break;

            case 4://DIV
                PC++;
                ACC/=Data[Arquivo_de_entrada[PC]];
                PC++;
            break;

            case 5://JMP
                PC++;
                PC=Arquivo_de_entrada[PC];
            break;
            
            case 6://JMPN
                PC++;
                if(ACC<0){
                    PC=Arquivo_de_entrada[PC];
                }else{
                    PC++;
                }

            break;

            case 7://JMPP
                PC++;
                if(ACC>0){
                    PC=Arquivo_de_entrada[PC];
                }else{
                    PC;;
                }

            break;

            case 8://JMPZ
                PC++;
                if(ACC==0){
                    PC=Arquivo_de_entrada[PC];
                }else{
                    PC++;
                }
            break;

            case 9://COPY
                PC++;
                Arquivo_de_entrada[PC+1]=Arquivo_de_entrada[PC];
                PC++;
                PC++;
            break;

            case 10://LOAD
                PC++;
                ACC=Arquivo_de_entrada[PC];
                PC++;
            break;

            case 11://STORE
                PC++;
                Data[PC]=ACC;
                PC++;
            break;

            case 12://INPUT
                PC++;
                cin>>input;
                Data[PC]=input;
                PC++;
            break;

            case 13://OUTPUT
                PC++;
                cout<<Data[PC]<<endl;
                PC++;
            break;

            case 14://STOP
                STOP=1;
                PC++;
            break;
        }
        
    }
}


int main(int argc, char *argv[]){
    Arquivo_de_entrada_str = Ler_entrada(argv[1]);
    char c;
    string aux_conversao;
    int n = Arquivo_de_entrada_str.size();
    for(int i=0; i<n;i++){//Transformando de str2int
        c = Arquivo_de_entrada_str.front();
        if(c!=' '){
            aux_conversao.push_back(c);
        }else{
            Arquivo_de_entrada.push_back(conversor_str_int(aux_conversao));
            aux_conversao.erase(aux_conversao.begin(),aux_conversao.end());
        }
        Arquivo_de_entrada_str.erase(Arquivo_de_entrada_str.begin());
    }


    for(int i=0; i<Arquivo_de_entrada.size();i++){
        cout<<Arquivo_de_entrada[i]<<" ";
    }
    cout<<endl;

    set_data();

    map<int, int>::iterator it;
    for(it=Data.begin();it!=Data.end();it++){//Sec data
        cout<<it->first<<" s:"<<it->second<<endl;
    }

    simulador();

    return 0;
}