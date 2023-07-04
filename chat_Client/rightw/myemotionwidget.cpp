#include "myemotionwidget.h"
#include "myemotionitemwidget.h"
#include "mylikesitemwidget.h"
#include "ui_myemotionwidget.h"
#include "chatwindow.h"

#include <QTableWidget>
#include <QTableWidgetItem>
MyEmotionWidget::MyEmotionWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyEmotionWidget)
{
    ui->setupUi(this);
    initEmotion();
    initLikes();
}

MyEmotionWidget::~MyEmotionWidget()
{
    delete ui;
}
//添加表情
void MyEmotionWidget::addEmotionItem(QString fileName)
{ // 获取当前添加到第几行第几列
    int row = m_emotionList.size()/ui->tableWidget->rowCount();
    int column = m_emotionList.size() % ui->tableWidget->rowCount();

    //qDebug()<<"row:"<<row<<"  "<<"column:"<<column<<"\n";
    QTableWidgetItem* tableWidgetItem = new QTableWidgetItem;
    ui->tableWidget->setItem(row, column, tableWidgetItem);


    MyEmotionItemWidget* cellWidget = new MyEmotionItemWidget(fileName);
    ui->tableWidget->setCellWidget(row, column, cellWidget);

    m_emotionList.push_back(fileName);
}
void MyEmotionWidget::addLikesItem(QString fileName)
{
    // 获取当前添加到第几行第几列
    int row = m_likesList.size()/ui->tableWidget_2->rowCount();
    int column = m_likesList.size() % ui->tableWidget_2->rowCount();

    //qDebug()<<"row:"<<row<<"  "<<"column:"<<column<<"\n";
    QTableWidgetItem* tableWidgetItem = new QTableWidgetItem;
    ui->tableWidget_2->setItem(row, column, tableWidgetItem);

    MyLikesItemWidget* cellWidget = new MyLikesItemWidget(fileName);
    ui->tableWidget_2->setCellWidget(row, column, cellWidget);

    m_likesList.push_back(fileName);
}
//初始化表情
void MyEmotionWidget::initEmotion()
{
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget->setMouseTracking(true);
    ui->tableWidget->installEventFilter(this);
    this->installEventFilter(this);

    QString path = ":/emotions/%1.gif";
    for (int i = 0; i < 12; i++)
    {
       // qDebug()<<"jiazai..."<<i;
        addEmotionItem(path.arg(i + 1));
    }
}
void MyEmotionWidget::initLikes()
{
    //this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    //ui->tableWidget_2->setFocusPolicy(Qt::NoFocus);

    QString path = ":/likes/%1.jpg";
    for (int i = 0; i < 12; i++)
    {
        addLikesItem(path.arg(i + 1));
    }
}
void MyEmotionWidget::on_tableWidget_cellClicked(int row, int column)
{

//    QTableWidgetItem *item = ui->tableWidget->item(row, column);
    // 获取该单元格所在的表格控件
//    QWidget* cellWidget=ui->tableWidget->cellWidget(row,column);
    MyEmotionItemWidget *myemoj=(MyEmotionItemWidget *)ui->tableWidget->cellWidget(row,column);
    currentFileName=myemoj->getFileName();
    //qDebug()<<"filename:"<<currentFileName;
    emit SendEmojoyMessage();
}


void MyEmotionWidget::on_pushButton_clicked()
{
    delete this;
}


void MyEmotionWidget::on_tableWidget_2_cellClicked(int row, int column)
{
    MyLikesItemWidget *mylike=(MyLikesItemWidget *)ui->tableWidget_2->cellWidget(row,column);
    currentFileName=mylike->getFileName();
    //qDebug()<<"filename:"<<currentFileName;
    emit SendEmojoyMessage();
    this->hide();
}

