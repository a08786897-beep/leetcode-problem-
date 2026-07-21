class Solution {
public:
    string defangIPaddr(string address) {
        string addres="";
        for(int i=0;i<address.size();i++){
            if(address[i] == '.'){
                addres +="[.]";
            }else{
                addres +=address[i];
            }
        }
        return addres;
    }
};