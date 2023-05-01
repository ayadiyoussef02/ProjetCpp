#ifndef EXPORTEXCEL_H
#define EXPORTEXCEL_H

#include <QObject>
#include <QTableView>
#include <QStringList>
#include <QSqlDatabase>

class EEO_Field
   {
   public:
       EEO_Field(const int ic, const QString &sf, const QString &st):
               iCol(ic),sFieldName(sf),sFieldType(st){}

       int     iCol;
       QString sFieldName;
       QString sFieldType;
   };

class ExportExcel : public QObject
{
    Q_OBJECT
public:
    ExportExcel(const QString &filepath, const QString &sheettitle,
                QTableView *tab_formation):excelFilePath(filepath),
                sheetName(sheettitle), tab_formation(tab_formation){}

    ~ExportExcel() {QSqlDatabase::removeDatabase("excelexport");}

public:
void setOutputFilePath(const QString &spath) {excelFilePath = spath;}
void setOutputSheetTitle(const QString &ssheet) {sheetName = ssheet;}
void setTableView(QTableView *tab_formation) {tab_formation = tab_formation;}

void addField(const int iCol, const QString &fieldname, const QString &fieldtype)
   {fieldList << new EEO_Field(iCol, fieldname, fieldtype);}

void removeAllFields()
   {while (!fieldList.isEmpty()) delete fieldList.takeFirst();}

int export2Excel();

signals:
void exportedRowCount(int row);

private:
QString excelFilePath;
QString sheetName;
QTableView *tab_formation;
QList<EEO_Field *> fieldList;
};

#endif // EXPORTEXCEL_H
