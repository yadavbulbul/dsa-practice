/*
Class diagram to code checklist
Use this flow when coding from the class diagram:

1. Start with the core entity

    Document
    owns content, metadata, versions, collaborators
2. Add the polymorphic content model

    DocumentElement
    TextElement
    ImageElement
3. Add the access layer

    User
    AccessControl
    permission checks before edits
4. Add versioning

    DocumentVersion
    snapshot creation when document changes
5. Add export behavior separately

    ExportStrategy
    PDFExportStrategy
    DOCXExportStrategy
    HTMLExportStrategy
6. Add the controller

    DocumentEditor
    orchestrates actions like addText, addImage, saveVersion, exportDocument
7. Code with modern C++ practices

    prefer unique_ptr
    avoid raw pointers unless absolutely needed
    keep interfaces abstract
    separate responsibilities cleanly

*/



#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

enum class ExportFormat {
    PDF,
    DOCX,
    HTML
};

class User {
private:
    string id;
    string name;
    bool canEdit;

public:
    User(string userId, string userName, bool editAccess)
        : id(move(userId)), name(move(userName)), canEdit(editAccess) {}

    const string& getId() const {
        return id;
    }

    const string& getName() const {
        return name;
    }

    bool hasEditAccess() const {
        return canEdit;
    }
};

class DocumentElement {
public:
    virtual ~DocumentElement() = default;
    virtual string render() const = 0;
};

class TextElement : public DocumentElement {
private:
    string text;

public:
    explicit TextElement(string value) : text(move(value)) {}

    string render() const override {
        return "Rendering Text Element: " + text;
    }
};

class ImageElement : public DocumentElement {
private:
    string imagePath;

public:
    explicit ImageElement(string path) : imagePath(move(path)) {}

    string render() const override {
        return "Rendering Image Element: " + imagePath;
    }
};

class DocumentVersion {
private:
    string versionId;
    string snapshot;

public:
    DocumentVersion(string id, string content)
        : versionId(move(id)), snapshot(move(content)) {}

    const string& getVersionId() const {
        return versionId;
    }

    const string& getSnapshot() const {
        return snapshot;
    }
};

class AccessControl {
private:
    unordered_map<string, bool> permissionMap;

public:
    void grantAccess(const User& user, bool editPermission) {
        permissionMap[user.getId()] = editPermission;
    }

    bool canEdit(const User& user) const {
        auto it = permissionMap.find(user.getId());
        return it != permissionMap.end() && it->second;
    }
};

class Document {
private:
    string id;
    string title;
    vector<unique_ptr<DocumentElement>> elements;
    vector<User> collaborators;
    vector<DocumentVersion> versions;
    AccessControl accessControl;

public:
    Document(string documentId, string documentTitle)
        : id(move(documentId)), title(move(documentTitle)) {}

    void addElement(unique_ptr<DocumentElement> element) {
        elements.push_back(move(element));
    }

    void shareWithUser(const User& user) {
        collaborators.push_back(user);
        accessControl.grantAccess(user, user.hasEditAccess());
    }

    bool canUserEdit(const User& user) const {
        return accessControl.canEdit(user);
    }

    void createVersion() {
        string snapshot;
        for (const auto& element : elements) {
            snapshot += element->render() + "\n";
        }
        versions.emplace_back("v" + to_string(versions.size() + 1), snapshot);
    }

    string renderDocument() const {
        string output;
        for (const auto& element : elements) {
            output += element->render() + "\n";
        }
        return output;
    }

    const string& getTitle() const {
        return title;
    }

    const string& getId() const {
        return id;
    }
};

class ExportStrategy {
public:
    virtual ~ExportStrategy() = default;
    virtual void exportDocument(const Document& doc, ExportFormat format) const = 0;
};

class PDFExportStrategy : public ExportStrategy {
public:
    void exportDocument(const Document& doc, ExportFormat format) const override {
        if (format != ExportFormat::PDF) {
            cout << "PDF strategy cannot export this format." << endl;
            return;
        }
        cout << "Exporting '" << doc.getTitle() << "' to PDF." << endl;
    }
};

class DOCXExportStrategy : public ExportStrategy {
public:
    void exportDocument(const Document& doc, ExportFormat format) const override {
        if (format != ExportFormat::DOCX) {
            cout << "DOCX strategy cannot export this format." << endl;
            return;
        }
        cout << "Exporting '" << doc.getTitle() << "' to DOCX." << endl;
    }
};

class HTMLExportStrategy : public ExportStrategy {
public:
    void exportDocument(const Document& doc, ExportFormat format) const override {
        if (format != ExportFormat::HTML) {
            cout << "HTML strategy cannot export this format." << endl;
            return;
        }
        cout << "Exporting '" << doc.getTitle() << "' to HTML." << endl;
    }
};

class DocumentEditor {
private:
    Document document;
    unique_ptr<ExportStrategy> exportStrategy;

public:
    DocumentEditor(string documentId, string title, unique_ptr<ExportStrategy> strategy)
        : document(move(documentId), move(title)), exportStrategy(move(strategy)) {}

    void addText(string text) {
        if (!document.canUserEdit(User("current-user", "Current User", true))) {
            cout << "Current user cannot edit this document." << endl;
            return;
        }
        document.addElement(make_unique<TextElement>(move(text)));
    }

    void addImage(string imagePath) {
        if (!document.canUserEdit(User("current-user", "Current User", true))) {
            cout << "Current user cannot edit this document." << endl;
            return;
        }
        document.addElement(make_unique<ImageElement>(move(imagePath)));
    }

    void shareWithUser(const User& user) {
        document.shareWithUser(user);
    }

    void saveVersion() {
        document.createVersion();
    }

    void renderDocument() const {
        cout << document.renderDocument();
    }

    void exportDocument(ExportFormat format) {
        exportStrategy->exportDocument(document, format);
    }
};

int main() {
    DocumentEditor editor("doc-101", "Team Meeting Notes", make_unique<PDFExportStrategy>());

    User alice("u-1", "Alice", true);
    User bob("u-2", "Bob", false);

    editor.shareWithUser(alice);
    editor.shareWithUser(bob);

    editor.addText("Agenda for today");
    editor.addImage("meeting-diagram.png");
    editor.saveVersion();
    editor.renderDocument();
    editor.exportDocument(ExportFormat::PDF);

    return 0;
}