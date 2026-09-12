/*
The Factory Pattern is used when you want to create objects without putting the object-creation logic everywhere in your code.

*/

/*
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

class ExportFactory{
public:
    ExportStrategy* createStrategy(string type){
        if(type=="pdf"){
            return new PDFExportStrategy();
        }else if(type=="docx"){
            return new DOCXExportStrategy();
        }else{
            return new HTMLExportStrategy();
        }
    }
};


Without Factory:

PDFExportStrategy pdf;
editor.exportDocument(&doc, &pdf);

With Factory:

ExportFactory factory;

ExportStrategy* strategy = factory.createStrategy("pdf");

editor.exportDocument(&doc, strategy);

The caller doesn't need to know that PDFExportStrategy exists or how to construct it.

That's the main purpose of the Factory Pattern.




The easiest way to remember
Pattern	          Think
Simple Factory	  "Give me one object based on a type."
Factory Method	  "The subclass decides which object to create."
Abstract Factory  "Give me a family of related objects."

For Factory Method:

The base class defines the creation method, and the subclasses decide which concrete object to create.

For Abstract Factory:

The factory provides multiple creation methods to create a family of related objects.

............

Factory Method uses inheritance where subclasses decide which object to create. Abstract Factory provides an interface for creating a family of related objects.
*/