/*
Strategy Pattern means:

Define multiple ways of doing something, put each way in its own class, and allow the behavior to be selected at runtime.

like we did in export strategy in google docs
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
*/
