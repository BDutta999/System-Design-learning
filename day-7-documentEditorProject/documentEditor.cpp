#include<bits/stdc++.h>
using namespace std;

class DocumentEditor{
private:
    vector<string> documentElements;
    string renderedDocument;

public:
    // add txt in form of plain string
    void addText(string text){
        documentElements.push_back(text);
    }
    // add image in form of file path   
    void addImage(string imagePath){
        documentElements.push_back(imagePath);
    }

    string renderDocument(){
        if(renderedDocument.empty()){
            string result;
            for(auto element : documentElements){
                if(element.size()>4 && (element.substr(element.size()-4)==".jpg" || element.substr(element.size()-4)==".png")){
                    result += "[Image: " + element + "]" + "\n";
                }
                else{
                    result += element + "\n";
                }
            }
            renderedDocument=result;
        }
        return renderedDocument;
    }

    void saveToFile(){
        ofstream file("document.txt");
        if(file.is_open()){
            file << renderDocument();
            file.close();
            cout<<"document saved to document.txt"<<endl;
        }
        else{
            cout<<"Unable to open file for writing"<<endl;
        }
    }
};

int main(){
    DocumentEditor editor;
    editor.addText("Hello");
    editor.addImage("picture.jpg");
    editor.addText("This is a document editor");

    cout<<editor.renderDocument()<<endl;
    editor.saveToFile();

}