#include "day12.h"



void day12::partOne(){
    using day12::node;
    std::vector<std::vector<std::string>> input_V = day12::readInput();
    std::vector<std::string> nodes;
    std::map<std::string, std::vector<std::string>> map = parseInput(input_V, nodes);
    
    //day12::node* myGraph = day12::createTree(map,nodes, "start");
    day12::print(day12::scam());
}


//! ### READ INPUT
std::vector<std::vector<std::string>> day12::readInput(){
    std::ifstream in("input");
    std::vector<std::string> input;
    
    for(std::string s;std::getline(in,s);){
        input.push_back(s);
    }

    std::vector<std::vector<std::string>> input_V;
    for(unsigned int i=0; i<input.size(); i++){
        std::string s1;
        std::string s2;
        bool first = true;
        std::vector<std::string> actual_string;
        for(unsigned int j=0; j<input[i].size(); j++){
            if(input[i][j]=='-')    first=false;
            if(first){
                s1+=input[i][j];
            }else if(input[i][j]!='-'){ 
                s2+=input[i][j];
            }
        }
        actual_string.push_back(s1);
        actual_string.push_back(s2);
        input_V.push_back(actual_string);
    }
    return input_V;
}

std::map<std::string, std::vector<std::string>> day12::parseInput(std::vector<std::vector<std::string>>& input_V, std::vector<std::string>& nodes){
    std::map<std::string,std::vector<std::string>> mappa;
    for(unsigned int i=0; i<input_V.size(); i++){
        if(i==0){
            nodes.push_back(input_V[0][0]);
            nodes.push_back(input_V[0][1]);
        }
        std::string s1=input_V[i][0];
        std::string s2=input_V[i][1];
        bool exist1=false;
        bool exist2=false;
        for(unsigned int j=0; j<nodes.size(); j++){
            if(s1==nodes[j])    exist1=true;
            if(s2==nodes[j])    exist2=true;
        }
        if(exist1!=true)    nodes.push_back(s1);
        if(exist2!=true)    nodes.push_back(s2);
    }
    for(unsigned int i=0; i<nodes.size(); i++){
        std::string key = nodes[i];
        std::vector<std::string> values;
        for(unsigned int j=0; j<input_V.size(); j++){
            if(input_V[j][0]==key)  values.push_back(input_V[j][1]);
            else if(input_V[j][1]==key) values.push_back(input_V[j][0]);
        }
        mappa.insert(std::pair<std::string, std::vector<std::string>>(nodes[i],values));
    }
    return mappa;

}

day12::node* day12::createTree(std::map<std::string, std::vector<std::string>>& map, std::vector<std::string>& nodes, std::string nodeName){
    
    node* nodo = new node();
    std::vector<node*> link;
    std::cout<<"s";
    for(unsigned int i=0; i<map[nodeName].size(); i++){
        node* tmp = createTree(map,nodes,map[nodeName][i]);
        nodo->links.push_back(tmp);
    }
    if(map[nodeName].size()==0) nodo->links.push_back(nullptr);
    nodo->value=nodeName;
    return nodo;
}

void day12::print(node* n){
    if(!n)  return;
    std::cout<<n->value<<std::endl;
    for(int i=0; i<n->links.size();i++){
        node* nn = n->links[i];
        print(nn);
    }
}

day12::node* day12::scam(){
    node *start = new node();
    node *ex = new node();
    node *NL = new node();
    node *um = new node();
    node* ql = new node();
    node *wv = new node();
    node *VF = new node();
    node *fo = new node();
    node *tg = new node();
    node *ZQ = new node();
    node *lx = new node();
    node *sb = new node();
    node *end = new node();

    ex->value="ex";
    NL->value="NL";
    um->value="um";
    ql->value="ql";
    wv->value="wv";
    VF->value="VF";
    fo->value="fo";
    start->value="start";
    end->value="end";
    tg->value="tg";
    ZQ->value="ZQ";
    lx->value="lx";
    sb->value="sb";
    ex->links.push_back(NL);
    ex->links.push_back(um);
    ex->links.push_back(lx);
    ex->links.push_back(wv);
    ex->links.push_back(fo);
    ex->links.push_back(VF);
    
    NL->links.push_back(ex);
    NL->links.push_back(start);
    NL->links.push_back(sb);
    NL->links.push_back(fo);
    NL->links.push_back(tg);
    
    um->links.push_back(ex);
    um->links.push_back(wv);
    um->links.push_back(end);

    ql->links.push_back(wv);
    ql->links.push_back(VF);
    ql->links.push_back(fo);
    ql->links.push_back(sb);

    wv->links.push_back(ql);
    wv->links.push_back(ZQ);
    wv->links.push_back(um);
    wv->links.push_back(ex);
    wv->links.push_back(fo);
    wv->links.push_back(end);

    VF->links.push_back(fo);
    VF->links.push_back(ql);
    VF->links.push_back(start);
    VF->links.push_back(sb);
    VF->links.push_back(ex);

    fo->links.push_back(VF);
    fo->links.push_back(ex);
    fo->links.push_back(ql);
    fo->links.push_back(NL);
    fo->links.push_back(wv);

    start->links.push_back(VF);
    start->links.push_back(NL);
    start->links.push_back(sb);

    end->links.push_back(tg);
    end->links.push_back(um);
    end->links.push_back(wv);

    tg->links.push_back(end);
    tg->links.push_back(NL);

    ZQ->links.push_back(wv);

    lx->links.push_back(ex);

    sb->links.push_back(start);
    sb->links.push_back(NL);
    sb->links.push_back(VF);
    sb->links.push_back(ql);

    return start;

}