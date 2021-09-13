#include <bits/stdc++.h>
using namespace std;

//Variaveis Globais
int ACC=0,PC=0;
typedef struct instr{
    string nome;
    int opcode;
    int tamanho;
}instrucao_def;
list<int*> Data;
map<int, instrucao_def> Mapa_de_Comando;
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

vector<instrucao_def> Cria_Tab_Comando(){//Tabela com Instruçoes sem Space e Const
    vector<instrucao_def> Tabela;
    instrucao_def instrucao;
    instrucao.nome="ADD";
    instrucao.opcode=1;
    instrucao.tamanho=2;
    Tabela.push_back(instrucao);
    
    instrucao.nome="SUB";
    instrucao.opcode=2;
    instrucao.tamanho=2;
    Tabela.push_back(instrucao);

    instrucao.nome="MUL";
    instrucao.opcode=3;
    instrucao.tamanho=2;
    Tabela.push_back(instrucao);

    instrucao.nome="DIV";
    instrucao.opcode=4;
    instrucao.tamanho=2;
    Tabela.push_back(instrucao);

    instrucao.nome="JMP";
    instrucao.opcode=5;
    instrucao.tamanho=2;
    Tabela.push_back(instrucao);

    instrucao.nome="JMPN";
    instrucao.opcode=6;
    instrucao.tamanho=2;
    Tabela.push_back(instrucao);

    instrucao.nome="JMPP";
    instrucao.opcode=7;
    instrucao.tamanho=2;
    Tabela.push_back(instrucao);

    instrucao.nome="JMPZ";
    instrucao.opcode=8;
    instrucao.tamanho=2;
    Tabela.push_back(instrucao);

    instrucao.nome="COPY";
    instrucao.opcode=9;
    instrucao.tamanho=3;
    Tabela.push_back(instrucao);

    instrucao.nome="LOAD";
    instrucao.opcode=10;
    instrucao.tamanho=2;
    Tabela.push_back(instrucao);

    instrucao.nome="STORE";
    instrucao.opcode=11;
    instrucao.tamanho=2;
    Tabela.push_back(instrucao);

    instrucao.nome="INPUT";
    instrucao.opcode=12;
    instrucao.tamanho=2;
    Tabela.push_back(instrucao);

    instrucao.nome="OUTPUT";
    instrucao.opcode=13;
    instrucao.tamanho=2;
    Tabela.push_back(instrucao);

    instrucao.nome="STOP";
    instrucao.opcode=14;
    instrucao.tamanho=1;
    Tabela.push_back(instrucao);
        
    return Tabela;
}

void set_data(){
    int opcode;
    for(int i=0; i<Arquivo_de_entrada.size();i++){//Colocando o PC no inicio do data section
        PC++;
        PC++;
        if(Arquivo_de_entrada[i]==9){//COPY
            PC++;
        }else if(Arquivo_de_entrada[i]==14){
            PC--;
            break;
        }
    }
    vector<int>::iterator it-=find(Arquivo_de_entrada.begin(),Arquivo_de_entrada.end(),14);
    ++it;//iterator tbm está no inicio do data_sec
    for(it; it!=Arquivo_de_entrada.end();++it){
        
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
    //inicializando PC e ACC em 16 bits de 0

    for(int i=0; i<Arquivo_de_entrada.size();i++){
        cout<<Arquivo_de_entrada[i]<<" ";
    }
    cout<<endl;



    return 0;
}