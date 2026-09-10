classDiagram
    class User {
        -string id
        -string name
        -bool canEdit
        +User(string userId, string userName, bool editAccess)
        +string getId() const
        +string getName() const
        +bool hasEditAccess() const
    }

    class DocumentElement {
        <<abstract>>
        +virtual ~DocumentElement()
        +virtual string render() const = 0
    }

    class TextElement {
        -string text
        +TextElement(string value)
        +string render() const override
    }

    class ImageElement {
        -string imagePath
        +ImageElement(string path)
        +string render() const override
    }

    class DocumentVersion {
        -string versionId
        -string snapshot
        +DocumentVersion(string id, string content)
        +string getVersionId() const
        +string getSnapshot() const
    }

    class AccessControl {
        -unordered_map<string, bool> permissionMap
        +void grantAccess(const User& user, bool editPermission)
        +bool canEdit(const User& user) const
    }

    class Document {
        -string id
        -string title
        -vector<unique_ptr<DocumentElement>> elements
        -vector<User> collaborators
        -vector<DocumentVersion> versions
        -AccessControl accessControl
        +Document(string documentId, string documentTitle)
        +void addElement(unique_ptr<DocumentElement> element)
        +void shareWithUser(const User& user)
        +bool canUserEdit(const User& user) const
        +void createVersion()
        +string renderDocument() const
        +string getTitle() const
        +string getId() const
    }

    class ExportStrategy {
        <<abstract>>
        +virtual ~ExportStrategy()
        +virtual void exportDocument(const Document& doc, ExportFormat format) const = 0
    }

    class PDFExportStrategy {
        +void exportDocument(const Document& doc, ExportFormat format) const override
    }

    class DOCXExportStrategy {
        +void exportDocument(const Document& doc, ExportFormat format) const override
    }

    class HTMLExportStrategy {
        +void exportDocument(const Document& doc, ExportFormat format) const override
    }

    class DocumentEditor {
        -Document document
        -unique_ptr<ExportStrategy> exportStrategy
        +DocumentEditor(string documentId, string title, unique_ptr<ExportStrategy> strategy)
        +void addText(string text)
        +void addImage(string imagePath)
        +void shareWithUser(const User& user)
        +void saveVersion()
        +void renderDocument() const
        +void exportDocument(ExportFormat format)
    }

    DocumentElement <|-- TextElement
    DocumentElement <|-- ImageElement
    ExportStrategy <|-- PDFExportStrategy
    ExportStrategy <|-- DOCXExportStrategy
    ExportStrategy <|-- HTMLExportStrategy

    Document "1" *-- "many" DocumentElement
    Document "1" *-- "many" User
    Document "1" *-- "many" DocumentVersion
    Document "1" *-- "1" AccessControl
    DocumentEditor "1" --> "1" Document
    DocumentEditor "1" --> "1" ExportStrategy