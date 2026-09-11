classDiagram

    class DocumentElement {
        <<abstract>>
        +render() string
    }

    class TextElement {
        -string text
        +TextElement(string text)
        +render() string
    }

    class ImageElement {
        -string imagePath
        +ImageElement(string imagePath)
        +render() string
    }

    class User {
        -string id
        -string name
        -bool canEdit
        +User(string id, string name, bool editAccess)
        +getId() string
        +getName() string
        +hasEditAccess() bool
    }

    class DocumentVersion {
        -string versionId
        -string snapshot
        +DocumentVersion(string id, string content)
        +getVersionId() string
        +getSnapshot() string
    }

    class Document {
        -string id
        -string title
        -vector~DocumentElement*~ elements
        -vector~DocumentVersion~ versions
        -vector~User~ collaborators
        +Document(string id, string title)
        +addElement(DocumentElement* element)
        +addCollaborator(User user)
        +addVersion(DocumentVersion version)
        +getSnapshot(DocumentElement* element)
    }

    class ExportStrategy {
        <<abstract>>
        +exportDocument(Document* doc) void
    }

    class PDFExportStrategy {
        +exportDocument(Document* doc) void
    }

    class DOCXExportStrategy {
        +exportDocument(Document* doc) void
    }

    class HTMLExportStrategy {
        +exportDocument(Document* doc) void
    }

    class DocumentEditor {
        +addText(Document* document, string text) void
        +addImage(Document* document, string imagePath) void
        +saveVersion(Document* document) void
        +exportDocument(Document* document, ExportStrategy* strategy) void
    }

    DocumentElement <|-- TextElement
    DocumentElement <|-- ImageElement

    Document "1" o-- "*" DocumentElement
    Document "1" o-- "*" DocumentVersion
    Document "1" o-- "*" User

    ExportStrategy <|-- PDFExportStrategy
    ExportStrategy <|-- DOCXExportStrategy
    ExportStrategy <|-- HTMLExportStrategy

    DocumentEditor --> Document
    DocumentEditor --> ExportStrategy