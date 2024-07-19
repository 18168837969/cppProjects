#include "VariablesWidget.h"

VariablesWidget::VariablesWidget(QWidget* parent) :
	BaseWidget(parent),
	ui(new Ui::VariablesWidget)
{
	ui->setupUi(this);
	ui->variableTable->setShowGrid(false);
	ui->variableTable->setSelectionMode(QAbstractItemView::NoSelection);
	ui->variableTable->setFocusPolicy(Qt::NoFocus);
	ui->variableTable->setColumnWidth(1, 80);
	ui->variableTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
	ui->variableTable->setFrameShape(QFrame::NoFrame);
	QPalette pal = ui->variableTable->palette();
	pal.setColor(QPalette::Base, GlobalColors::KayexBlack);
	pal.setColor(QPalette::AlternateBase, GlobalColors::KayexGray);
	ui->variableTable->setAlternatingRowColors(true);
	ui->variableTable->setPalette(pal);
	ui->variableTable->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	for (int row = 0; row < ui->variableTable->rowCount(); ++row) {
		for (int col = 0; col < ui->variableTable->colorCount(); ++col) {
			QTableWidgetItem* item = new QTableWidgetItem(QString("Row %1, Col %2").arg(row).arg(col));
			item->setForeground(GlobalColors::KayexWhite);
			ui->variableTable->setItem(row, col, item);
		}
	}
	connect(ui->variableTable, &QTableWidget::cellDoubleClicked, this, [&]() {
		emit widgetDoubleClicked();
		});
}

VariablesWidget::~VariablesWidget()
{
	delete ui;
}