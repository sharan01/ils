#ifndef ADDBOOKWIZARD_H
#define ADDBOOKWIZARD_H

#include <vector>
#include <QWizard>
#include <QtWidgets>
#include "bookinfoonline.h"

class AddBookWizard : public QWizard
{
    Q_OBJECT
public:
    explicit AddBookWizard(QWidget *parent = 0);

    void accept();
    
signals:
    
public slots:



};

// first page
class DetailsPage : public QWizardPage
{
    Q_OBJECT

public:
    DetailsPage(QWidget *parent = 0);
public slots:
     void getBookInfoOnline();

private:
    QLabel *ISBNLabel;
    QLabel *titleLabel;
    QLabel *authorLabel;
    QLabel *publisherLabel;
    QLabel *publishedDateLabel;
    QLabel *branchLabel;
    QLabel *copiesLabel;

    QLineEdit *ISBNEdit;
    QLineEdit *titleEdit;
    QLineEdit *authorEdit;
    QLineEdit *publisherEdit;
    QLineEdit *publishedDateEdit;
    //branch combo box
    QLineEdit *copiesEdit;

    QComboBox *branchSelector;

    QPushButton *fetchInfo;

    QGridLayout *layout;

    BookInfoOnline bookInfoOnline;

    void createWidgets();
    void createLayouts();
    void createConnections();

    void registerFields();
};



class FinalPage : public QWizardPage
{
    Q_OBJECT
public:
    FinalPage(QWidget *parent = 0);

    void initializePage();

public slots:

private:
    std::vector<QLineEdit *> bookNoEdits;
    QGridLayout *layout;

};

#endif // ADDBOOKWIZARD_H