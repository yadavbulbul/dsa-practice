#include<iostream>
#include<string>
#include<vector>
using namespace std;

//abstract class
class DocumentElement{
public:
    virtual string render() = 0;
    virtual ~DocumentElement(){}
};

//childclasses
class TextElement:public DocumentElement{
private:
    string text;
public:
    TextElement(string text){
        this->text=text;
    }
    string render() override{
        return "Text: "+text;
    }
};

class ImageElement:public DocumentElement{
private:
    string imagePath;
public:
    ImageElement(string imagePath){
        this->imagePath=imagePath;
    }
    string render() override{
        //business logic for displaying image
        return "Image: "+imagePath;
    }
};


class User{
private:
    string id;
    string name;
    bool canEdit;
public:
    User(string userId,string userName,bool editAccess){
        this->id=userId;
        this->name=userName;
        this->canEdit=editAccess;
    }
    string getId(){
        return id;
    }
    string getName(){
        return name;
    }
    bool hasEditAccess(){
        return canEdit;
    }
};

class DocumentVersion{
private:
    string versionId;
    string snapshot;
public:
    DocumentVersion(string id,string content){
        this->versionId=id;
        this->snapshot=content;
    }
    string getVersionId(){
        return versionId;
    }
    string getSnapshot(){
        return snapshot;
    }
};

class Document{
private:
    string id;
    string title;
    vector<DocumentElement*>elements;
    vector<DocumentVersion>versions;
    vector<User>collaborators;
public:
    Document(string id,string title){
        this->id=id;
        this->title=title;
    }

    void addElement(DocumentElement* element){
        elements.push_back(element);
    }

    void addCollaborator(User user){
        collaborators.push_back(user);
    }

    void addVersion(DocumentVersion version){
        versions.push_back(version);
    }

    string getSnapshot(){
        string snapshot = "";
        for(DocumentElement* element : elements){
            snapshot += element->render();
            snapshot += "\n";
        }
        return snapshot;
    }

};

//abstract class
class ExportStrategy{
public:
    virtual void exportDocument(Document* doc) = 0;
    virtual ~ExportStrategy(){}
};

//child
class PDFExportStrategy:public ExportStrategy{
public:
    void exportDocument(Document* doc){
        //logic to export in pdf
        cout<<"Doc exported in PDF format";
    }
};
class DOCXExportStrategy:public ExportStrategy{
public:
    void exportDocument(Document* doc){
        //logic to export in docx
        cout<<"Doc exported in DOCX format";
    }
};
class HTMLExportStrategy:public ExportStrategy{
public:
    void exportDocument(Document* doc){
        //logic to export in html
        cout<<"Doc exported in HTML format";
    }
};


//controller
class DocumentEditor{
public:
    void addText(Document* doc, string text){
        TextElement* element = new TextElement(text);

        doc->addElement(element);
    }

    void addImage(Document* doc,string imagePath){
        ImageElement* element = new ImageElement(imagePath);
        doc->addElement(element);
    }

    void saveVersion(Document* doc) {
        string snapshot = doc->getSnapshot();

        DocumentVersion version("V1", snapshot);

        doc->addVersion(version);
    }

    void exportDocument(Document* doc,ExportStrategy* strategy){
        strategy->exportDocument(doc);
    }
};

int main(){

    //create a document
    Document doc("D1","Document 1");

    DocumentEditor editor;

    editor.addText(&doc,"text1");

    editor.addImage(&doc,"image.png");

    editor.saveVersion(&doc);

    //Export as PDF
    PDFExportStrategy pdf;
    editor.exportDocument(&doc, &pdf);
    
    return 0;
}