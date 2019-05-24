#include "quicreator.h"
#include "ui_quicreator.h"
#include "qfile.h"
#include "qtranslator.h"
#include "qdesktopwidget.h"
#include <iostream>
#include"global.h"
#include<string.h>
#include"Parser.h"
#include<iomanip>
#include<stdio.h>
#include<windows.h>
#include<fstream>
#include<string.h>
#include<qstring.h>
#include<cstring>
#include<lex.h>
#include <qtextcodec.h>
#include <qlabel.h>
#include <QDesktopServices>
#include <QUrl>
#include "Highlighter.h"
#include <QFileDialog>
#include <QFileDevice>
#include <QFile>
#include <QMessageBox>
#include <QtEvents>
#include <QTextStream>
//#include"global.h"
#include<QProcess>
#pragma execution_character_set("utf-8")


QUICreator::QUICreator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QUICreator)
{
    ui->setupUi(this);
    this->initForm();
}

QUICreator::~QUICreator()
{
    delete ui;
}

void QUICreator::initForm()
{

    this->initStyle();

}


void QUICreator::initStyle()
{
    //加载样式表
    QFile file(":/qss/psblack.css");
    //QFile file(":/qss/flatwhite.css");
   //QFile file(":/qss/lightblue.css");
    if (file.open(QFile::ReadOnly)) {
        QString qss = QLatin1String(file.readAll());
        QString paletteColor = qss.mid(20, 7);
        qApp->setPalette(QPalette(QColor(paletteColor)));
        qApp->setStyleSheet(qss);
        file.close();
    }
}

void QUICreator::initTranslator()
{
    //加载鼠标右键菜单翻译文件
    QTranslator *translator1 = new QTranslator(qApp);
    translator1->load(":/image/qt_zh_CN.qm");
    qApp->installTranslator(translator1);

    //加载富文本框鼠标右键菜单翻译文件
    QTranslator *translator2 = new QTranslator(qApp);
    translator2->load(":/image/widgets.qm");
    qApp->installTranslator(translator2);
}

void QUICreator::on_textEdit_textChanged(){}
//这些东西都是定义好但是后期没有用删了会报错
void QUICreator::initTableWidget(){}
void QUICreator::initTreeWidget(){}
void QUICreator::initListWidget(){}
void QUICreator::initOther(){}
void QUICreator::on_action_C_triggered(){}

//void QUICreator::on_textEdit_2_textChanged()
//{
//    QTextEdit* pEdit = new QTextEdit();

//    Highlighter * h = new Highlighter(pEdit->document());//传一个QTextDocument


//    QString text = ui->textEdit_2->toPlainText();

//       QStringList number_list = text.split("\n");
//       std::ofstream fout( "..\\demo\\mid\\test.c" );
//       if (!fout)
//       {
//        printf("文件不能打开\n");
//       }
//       for (int i = 0; i < number_list.size(); ++i)
//       {
//           number_list[i]+='\n';
//           QByteArray sr=number_list[i].toLocal8Bit();
//           char ch[40];
//           strcpy(ch,sr.data());
//           fout<<ch;
//       }
//       fout.close();
//}


void QUICreator::on_textEdit_2_textChanged()
{



   QString text = ui->textEdit_2->toPlainText();
    //char *text1;
   // highlight(text1,KEYWORDS);

       QStringList number_list = text.split("\n");
       std::ofstream fout( "..\\demo\\mid\\test.c" );
       if (!fout)
       {
        printf("文件不能打开\n");
       }
       for (int i = 0; i < number_list.size(); ++i)
       {
           number_list[i]+='\n';
           QByteArray sr=number_list[i].toLocal8Bit();
           char ch[40];
           strcpy(ch,sr.data());
           fout<<ch;
       }
       fout.close();
}

void QUICreator::on_action_1_triggered()
{
    ui->textEdit->clear();
    ui->textEdit_3->clear();
   filename = (char *)malloc(100);
              strcpy(filename,"..\\demo\\mid\\test.c");
              if(!(source = fopen(filename,"r+")))
              {
                  cerr<<"No such file or dictionary!"<<endl;
                  exit(0);
              }
              errorjilu.str("");
              string temp;
              lex = new Lex(filename);
              lex->analysis();
              if(errorNum>0) {errorjilu<<"\t=== Build finished: "<<errorNum<<" error(s), "<<warnNum<<" warning(s) ==="<<endl;
                   temp=errorjilu.str();
                   QString result=QString::fromStdString(temp);
                   ui->textEdit_3->append(result);
              }
              else
                  {
                  errorjilu<<"\t=== Build finished: 0 error(s), "<<warnNum<<" warning(s) ==="<<endl;
                  temp=errorjilu.str();
                  QString result=QString::fromStdString(temp);
                  ui->textEdit_3->append(result);
                  lex->LexShow();
                  char buffer[256];
                     ifstream in("..\\demo\\mid\\Lex.txt");//文件不存在会返回错误
                     if (! in.is_open()){
                         cout << "Error opening file"<<endl;
                         exit (1);
                     }
                     while (!in.eof()){
                         in.getline (buffer,100);
                         ui->textEdit->append(QString::fromUtf8(buffer));
                      }
              }
              errorNum=0;
              warnNum=0;
    delete filename;
}

void QUICreator::on_action_2_triggered()
{
    ui->textEdit->clear();
    ui->textEdit_3->clear();
   filename = (char *)malloc(100);
             strcpy(filename,"..\\demo\\mid\\test.c");
             if(!(source = fopen(filename,"r+")))
             {
                 cerr<<"No such file or dictionary!"<<endl;
                 exit(0);
             }
              errorjilu.str("");
             Parser *parser = new Parser(filename);
             parser->analyze();
               string temp;
             if(errorNum>0) {errorjilu<<"\t=== Build finished: "<<errorNum<<" error(s), "<<warnNum<<" warning(s)==="<<endl;
                 temp=errorjilu.str();
                 QString result=QString::fromStdString(temp);
                 ui->textEdit_3->append(result);}
             else
                 {
                 errorjilu<<"\t=== Build finished: 0 error(s), "<<warnNum<<" warning(s) ==="<<endl;
                 temp=errorjilu.str();
                 QString result=QString::fromStdString(temp);
                 ui->textEdit_3->append(result);
                 parser->DrawTree();
                 char buffer[256];
                    ifstream in("..\\demo\\mid\\Parse.txt");//文件不存在会返回错误
                    if (! in.is_open()){
                        cout << "Error opening file"<<endl;
                        exit (1);
                    }
                    while (!in.eof()){
                        in.getline (buffer,100);
                        ui->textEdit->append(QString::fromUtf8(buffer));
                     }
             }
             symtab->varTab.clear();
             symtab->strTab.clear();
             symtab->funTab.clear();
              lbNum=0;
             errorNum=0;
             warnNum=0;
             delete parser;
       free(filename);
}

void QUICreator::on_action_3_triggered()
{
    ui->textEdit_3->clear();
    filename = (char *)malloc(1000);
                    strcpy(filename,"..\\demo\\mid\\test.c");//add-delete
                  if(!(source = fopen(filename,"r+")))
                   {
                       cerr<<"No such file or dictionary!"<<endl;
                       exit(0);
                   }
                   errorjilu.str("");
                   Parser *parser = new Parser(filename);
                    string temp;
                   parser->analyze();
                   if(errorNum>0) {errorjilu<<"\t=== Build finished: "<<errorNum<<" error(s), "<<warnNum<<" warning(s)==="<<endl;
                       temp=errorjilu.str();
                       QString result=QString::fromStdString(temp);
                       ui->textEdit_3->append(result);}
                   else
                   {
                       errorjilu<<"\t=== Build finished: 0 error(s), "<<warnNum<<" warning(s) ==="<<endl;
                       temp=errorjilu.str();
                       QString result=QString::fromStdString(temp);
                       ui->textEdit_3->append(result);
                       symtab->ShowIR();
                       ifstream inFile2("..\\demo\\mid\\Intercode.txt");
                       std::string s2;
                       QString qs2;
                       string line;
                       if(inFile2)
                       {
                           while (getline (inFile2, line)) // line
                           {
                               cout<<line<<endl;
                               s2=s2+line+"\n";
                           }
                       }
                        qs2=QString::fromStdString(s2);
                      ui->textEdit->setText(qs2);
                   }
                   symtab->varTab.clear();
                   symtab->strTab.clear();
                   symtab->funTab.clear();
                   lbNum=0;
                   errorNum=0;
                   warnNum=0;
                    delete parser;
                    free(filename);
}

void QUICreator::on_action_6_triggered()
{
      QFile file(":/qss/lightblue.css");
     if (file.open(QFile::ReadOnly)) {
         QString qss = QLatin1String(file.readAll());
         QString paletteColor = qss.mid(20, 7);
         qApp->setPalette(QPalette(QColor(paletteColor)));
         qApp->setStyleSheet(qss);
         file.close();
     }
}

void QUICreator::on_action_7_triggered()
{
    //QFile file(":/qss/psblack.css");
    QFile file(":/qss/flatwhite.css");
   //QFile file(":/qss/lightblue.css");
    if (file.open(QFile::ReadOnly)) {
        QString qss = QLatin1String(file.readAll());
        QString paletteColor = qss.mid(20, 7);
        qApp->setPalette(QPalette(QColor(paletteColor)));
        qApp->setStyleSheet(qss);
        file.close();
    }
}

void QUICreator::on_action_8_triggered()
{
    QFile file(":/qss/psblack.css");
    //QFile file(":/qss/flatwhite.css");
   //QFile file(":/qss/lightblue.css");
    if (file.open(QFile::ReadOnly)) {
        QString qss = QLatin1String(file.readAll());
        QString paletteColor = qss.mid(20, 7);
        qApp->setPalette(QPalette(QColor(paletteColor)));
        qApp->setStyleSheet(qss);
        file.close();
    }
}

void QUICreator::on_action_4_triggered()
{
    ui->textEdit_3->clear();
    filename = (char *)malloc(1000);
             strcpy(filename,"..\\demo\\mid\\test.c");//add-delete
                   if(!(source = fopen(filename,"r+")))
                   {
                       cerr<<"No such file or dictionary!"<<endl;
                       exit(0);
                   }
                   errorjilu.str("");
                   Parser *parser = new Parser(filename);
                    string temp;
                   parser->analyze();
                   if(errorNum>0) {errorjilu<<"\t=== Build finished: "<<errorNum<<" error(s), "<<warnNum<<" warning(s)==="<<endl;
                       temp=errorjilu.str();
                       QString result=QString::fromStdString(temp);
                       ui->textEdit_3->append(result);}
                   else
                   {
                       errorjilu<<"\t=== Build finished: 0 error(s), "<<warnNum<<" warning(s) ==="<<endl;
                       temp=errorjilu.str();
                       QString result=QString::fromStdString(temp);
                       ui->textEdit_3->append(result);
                       file = fopen("temp.s","w+");
                       //"CON"
                       if((file = freopen("..\\demo\\mid\\huibian.s","w",file))==NULL) {cerr<<"File redirect failed"<<endl;exit(0);}
                       symtab->genAsm();
                       fclose(file);
                       ///////////////////////////////////////
                       ifstream inFile3("..\\demo\\mid\\huibian.s");
                       std::string s3;
                       QString qs3;
                       string line;
                       if(inFile3)
                       {
                           while (getline (inFile3, line)) // line
                           {
                               cout<<line<<endl;
                               s3=s3+line+"\n";
                           }
                       }
                        qs3=QString::fromStdString(s3);
                      ui->textEdit->setText(qs3);
                   }
                   symtab->varTab.clear();
                   symtab->strTab.clear();
                   symtab->funTab.clear();
                    lbNum=0;
                   errorNum=0;
                   warnNum=0;
                   delete parser;
                    free(filename);
}
   //const QUrl url(http://www.baidu.com);
void QUICreator::on_action_9_triggered()
{

QDesktopServices::openUrl(QUrl(QLatin1String("C:/Users/fang/Desktop/Cmini/demo/aboutme.html")));
}

void QUICreator::on_action_C_2_triggered()
{

}

int flag_isOpen = 0;
int flag_isNew = 0;
QString Last_FileName;
QString Last_FileContent;
//打开文件
void QUICreator::on_action_O_triggered()
{
    QString fileName;
        fileName = QFileDialog::getOpenFileName(this,"Open File","","Text File(*.txt)");
        if(fileName == "")
        {
            return ;
        }
        else
        {
            QFile file(fileName);
            if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                QMessageBox::warning(this,"error","open file error!");
                return;
            }
            else
            {
                if(!file.isReadable())
                    QMessageBox::warning(this,"error","this file is not readable!");
                else
                {
                    QTextStream textStream(&file);
                    while(!textStream.atEnd())
                    {
                        ui->textEdit_2->setPlainText(textStream.readAll());
                    }
                    ui->textEdit_2->show();
                    file.close();
                    flag_isOpen = 1;
                    Last_FileName = fileName;
                }
            }
        }

}
//新建文件
void QUICreator::on_action_triggered()
{
    ui->textEdit_2->clear();
        ui->textEdit_2->setHidden(false);
        flag_isNew = 1;
        flag_isOpen = 1;
}

//保存文件
void QUICreator::on_action_S_triggered()
{
    if(flag_isNew)
        {
            if(ui->textEdit_2->toPlainText()=="")
            {
                QMessageBox::warning(this,"error","content can not be none!",QMessageBox::Ok);
            }
            else
            {
                QFileDialog fileDialog;
                QString str = fileDialog.getSaveFileName(this,"Open File","","Text File(*.txt)");
                if(str == "")
                {
                    return;
                }
                QFile filename(str);
                if(!filename.open(QIODevice::WriteOnly | QIODevice::Text))
                {
                    QMessageBox::warning(this,"error","Open File Error!");
                    return;
                }
                else
                {
                    QTextStream textStream(&filename);
                    QString str = ui->textEdit->toPlainText();
                    textStream << str;
                    Last_FileContent =str;
                }
                QMessageBox::information(this,"Ssve File","Save File Success",QMessageBox::Ok);
                filename.close();
                flag_isNew = 0;
                Last_FileName = str;
            }
        }
        else
        {
            if(flag_isOpen)
            {
                QFile file(Last_FileName);
                if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
                {
                    QMessageBox::warning(this,"error","Open File Faile");
                    return;
                }
                else
                {
                    QTextStream textString(&file);
                    QString str = ui->textEdit_2->toPlainText();
                    textString << str;
                    Last_FileContent = str;
                    file.close();
                }
            }
            else
            {
                QMessageBox::warning(this,"Warning","Please new or open a file");
                return;
            }

        }

}

//另存文件
void QUICreator::on_action_10_triggered()
{
    QFileDialog fileDialog;
       QString fileName = fileDialog.getSaveFileName(this,"Open File","","Text File(*.c)");
       if(fileName == "")
       {
           return;
       }
       QFile file(fileName);
       if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
       {
           QMessageBox::warning(this,"error","open file failure!");
           return;
       }
       else
       {
           QTextStream textStream(&file);
           QString str = ui->textEdit_2->toPlainText();
           textStream<<str;
           QMessageBox::warning(this,"tip","Save File Success!");
           Last_FileContent = str;
           Last_FileName = fileName;
           flag_isNew = 0;
           file.close();
       }

}
//运行
void QUICreator::on_action_5_triggered()
{
         //  ui->textEdit_3->clear();
           QProcess myProcess;
           myProcess.start("cmd.exe",QStringList()<<"/c"<<"start"<<"..\\demo\\mid\\pause.bat");
           myProcess.waitForFinished();

}
//生成可执行文件
void QUICreator::on_action_11_triggered()
{
  //  ui->textEdit_3->clear();

    QProcess myProcess;
          QString program;
          program.append("cmd.exe");
          QStringList arguments;
          arguments<<"/c"<<"gcc -m32 ..\\demo\\mid\\huibian.s -o ..\\bin\\huibian";
          myProcess.start(program, arguments);
          myProcess.waitForFinished();
          QString strTemp = "成功生成可执行文件";
          ui->textEdit->setText(strTemp);
}
