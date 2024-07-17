#pragma once
#include <QWidget>
#include "ui_mainControl.h"
#include "pch.h"
namespace Ui {
	class mainControl;
}

class mainControl : public QWidget
{
	Q_OBJECT

public:
	explicit mainControl(QWidget* parent = nullptr);
	~mainControl();

	enum EnumCtrlBtn
	{
		NullBtn = -1,
		SeedLift,
		SeedRot,
		CrucLift,
		CrucRot,
		HtrPower,
		Image,
		CrucPos,
		ShieldPos,
		DiaCtrl,
		HtrTemp,
		HtrTempRate,
		MeltTemp,
		GrowthCtrl,
		MeltGap,
		MeltPos,
		PressCtrl
	};
	struct mainCtrlStruct
	{
		int pos{ 0 };
		QString name{};
		QPushButton* ctrlBtn = nullptr;
	};
	QMap<EnumCtrlBtn, mainCtrlStruct> mainCtrlBtnMap{
			{ SeedLift, { 0, "晶升" } },
			{ SeedRot, { 0, "晶转" } },
			{ CrucLift, { 0, "埚升" } },
			{ CrucRot, { 0, "埚转" } },
			{ HtrPower, { 0, "加热器功率" } },
			{ Image, { 0, "图像" } },
			{ CrucPos, { 0, "坩埚位置" } },

			{ DiaCtrl, { 1, "直径控制" } },
			{ HtrTemp, { 1, "热场温度" } },
			{ HtrTempRate, { 1, "热场温度\n变化速率" } },
			{ MeltGap, { 1, "液面温度" } },
			{ GrowthCtrl, { 1, "生长控制" } },
			{ MeltGap, { 1, "液面位置\n液口距" } },
			{ MeltPos, { 1, "液面位置\n埚跟比" } },
			{ PressCtrl, { 1, "压力控制" } },



	};
public slots:
	void ctrlBtnClicked(bool isChecked);

private:
	Ui::mainControl* ui;
	QPushButton* _lastActiveBtn = nullptr;
};