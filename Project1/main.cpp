#include <stdio.h>
#include "tinyxml2.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace tinyxml2;
using namespace std;

struct GeometryData
{
	int ToothIndex;
	string System;
	string Name;
	string ID;
	double PositionX;
	double PositionY;
	double PositionZ;
	double DirectionX;
	double DirectionY;
	double DirectionZ;
	double RotationX;
	double RotationY;
	double RotationZ;
	double TransformMatrix[4][4];
	double xAxisX;
	double xAxisY;
	double xAxisZ;
	double yAxisX;
	double yAxisY;
	double yAxisZ;
	double zAxisX;
	double zAxisY;
	double zAxisZ;
};

std::ostream& operator<<(std::ostream& out, const GeometryData& d)
 {
	cout << "ToothIndex: " << d.ToothIndex << "\n";
	cout << "System: " << d.System << "\n";
	cout << "Name: " << d.Name << "\n";
	cout << "ID: " << d.ID << "\n";
	cout << "Position: " << "(" << d.PositionX << "," << d.PositionY << "," << d.PositionZ << ")\n";
	cout << "Direction: " << "(" << d.DirectionX << "," << d.DirectionY << "," << d.DirectionZ << ")\n";
	cout << "Rotation: " << "(" << d.RotationX << "," << d.RotationY << "," << d.RotationZ << ")\n";
	cout << "TransformMatrix: " << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << d.TransformMatrix[i][j] << "		";
		}
		cout << endl;
	}
	cout << "xAxis: " << "(" << d.xAxisX << "," << d.xAxisY << "," << d.xAxisZ << ")\n";
	cout << "yAxis: " << "(" << d.yAxisX << "," << d.yAxisY << "," << d.yAxisZ << ")\n";
	cout << "zAxis: " << "(" << d.zAxisX << "," << d.zAxisY << "," << d.zAxisZ << ")\n";
	return out;
	}



GeometryData parseXML(const char fileName[])
{

	GeometryData d;
	tinyxml2::XMLDocument xml_doc;


	tinyxml2::XMLError eResult = xml_doc.LoadFile(fileName);
	if (eResult != tinyxml2::XML_SUCCESS) 
	{
		cout << "Error"; 
		exit(1);
	}


	tinyxml2::XMLNode* root = xml_doc.FirstChildElement("root");
	if (root == nullptr) 
	{
		cout << "Error";
		exit(1);
	}


	tinyxml2::XMLElement* TI = root->FirstChildElement("ToothIndex");
	if (TI == nullptr) 
	{
		cout << "Error";
		exit(1);
	}
	d.ToothIndex = std::stod(TI->Attribute("unn"));


	tinyxml2::XMLElement* Kit = TI->FirstChildElement("Kit");
	if (Kit == nullptr) 
	{
		cout << "Error";
		exit(1);
	}


	tinyxml2::XMLElement* SYSTEM = Kit->FirstChildElement("System");
	if (SYSTEM == nullptr) 
	{
		cout << "Error";
		exit(1);
	}
	d.System = (SYSTEM->Attribute("value"));


	tinyxml2::XMLElement* NAME = Kit->FirstChildElement("Name");
	if (NAME == nullptr)  
	{
		cout << "Error";
		exit(1);
	}
	d.Name = (NAME->Attribute("value"));


	tinyxml2::XMLElement* id = Kit->FirstChildElement("ID");
	if (id == nullptr) 
	{
		cout << "Error";
		exit(1);
	}
	d.ID = (id->Attribute("value"));


	tinyxml2::XMLElement* Position = TI->FirstChildElement("Position");
	if (Position == nullptr) 
	{
		cout << "Error";
		exit(1);
	}
	d.PositionX = std::stod(Position->Attribute("x"));
	d.PositionY = std::stod(Position->Attribute("y"));
	d.PositionZ = std::stod(Position->Attribute("z"));

	tinyxml2::XMLElement* Direction = TI->FirstChildElement("Direction");
	if (Direction == nullptr) 
	{
		cout << "Error";
		exit(1);
	};
	d.DirectionX = std::stod(Direction->Attribute("x"));
	d.DirectionY = std::stod(Direction->Attribute("y"));
	d.DirectionZ = std::stod(Direction->Attribute("z"));


	tinyxml2::XMLElement* Rotation = TI->FirstChildElement("Rotation");
	if (Rotation == nullptr) 
	{
		cout << "Error";
		exit(1);
	}
	d.RotationX = std::stod(Rotation->Attribute("x"));
	Rotation = Rotation->NextSiblingElement("Rotation");
	if (Rotation == nullptr) 
	{
		cout << "Error";
		exit(1);
	};
	d.RotationY = std::stod(Rotation->Attribute("y"));
	Rotation = Rotation->NextSiblingElement("Rotation");
	if (Rotation == nullptr) 
	{
		cout << "Error";
		exit(1);
	}
	d.RotationZ = std::stod(Rotation->Attribute("z"));


	tinyxml2::XMLElement* TransformMatrix = TI->FirstChildElement("TransformMatrix");
	if (TransformMatrix == nullptr) 
	{
		cout << "Error";
		exit(1);
	}
	d.TransformMatrix[0][0] = std::stod(TransformMatrix->Attribute("m00"));
	d.TransformMatrix[0][1] = std::stod(TransformMatrix->Attribute("m01"));
	d.TransformMatrix[0][2] = std::stod(TransformMatrix->Attribute("m02"));
	d.TransformMatrix[0][3] = std::stod(TransformMatrix->Attribute("m03"));
	d.TransformMatrix[1][0] = std::stod(TransformMatrix->Attribute("m10"));
	d.TransformMatrix[1][1] = std::stod(TransformMatrix->Attribute("m11"));
	d.TransformMatrix[1][2] = std::stod(TransformMatrix->Attribute("m12"));
	d.TransformMatrix[1][3] = std::stod(TransformMatrix->Attribute("m13"));
	d.TransformMatrix[2][0] = std::stod(TransformMatrix->Attribute("m20"));
	d.TransformMatrix[2][1] = std::stod(TransformMatrix->Attribute("m21"));
	d.TransformMatrix[2][2] = std::stod(TransformMatrix->Attribute("m22"));
	d.TransformMatrix[2][3] = std::stod(TransformMatrix->Attribute("m23"));
	d.TransformMatrix[3][0] = std::stod(TransformMatrix->Attribute("m30"));
	d.TransformMatrix[3][1] = std::stod(TransformMatrix->Attribute("m31"));
	d.TransformMatrix[3][2] = std::stod(TransformMatrix->Attribute("m32"));
	d.TransformMatrix[3][3] = std::stod(TransformMatrix->Attribute("m33"));


	tinyxml2::XMLElement* Xaxis = TI->FirstChildElement("Xaxis");
	if (Xaxis == nullptr) 
	{
		cout << "Error";
		exit(1);
	}
	d.xAxisX = std::stod(Xaxis->Attribute("x"));
	d.xAxisY = std::stod(Xaxis->Attribute("y"));
	d.xAxisZ = std::stod(Xaxis->Attribute("z"));


	tinyxml2::XMLElement* Yaxis = TI->FirstChildElement("Yaxis");
	if (Yaxis == nullptr) 
	{
		cout << "Error";
		exit(1);
	}
	d.yAxisX = std::stod(Yaxis->Attribute("x"));
	d.yAxisY = std::stod(Yaxis->Attribute("y"));
	d.yAxisZ = std::stod(Yaxis->Attribute("z"));


	tinyxml2::XMLElement* Zaxis = TI->FirstChildElement("Zaxis");
	if (Zaxis == nullptr) 
	{
		cout << "Error";
		exit(1);
	}
	d.zAxisX = std::stod(Zaxis->Attribute("x"));
	d.zAxisY = std::stod(Zaxis->Attribute("y"));
	d.zAxisZ = std::stod(Zaxis->Attribute("z"));


	return d;
}

int main()
{
	GeometryData d0 = parseXML("01000_20160314_1152_Inselsberger_ImplantDirectionPosition_0.xml");
	GeometryData d1 = parseXML("01000_20160314_1152_Inselsberger_ImplantDirectionPosition_1.xml");
	GeometryData d2 = parseXML("01000_20160314_1152_Inselsberger_ImplantDirectionPosition_2.xml");
	GeometryData d3 = parseXML("01000_20160314_1152_Inselsberger_ImplantDirectionPosition_3.xml");
	cout << d0 << endl;
	cout << d1 << endl;
	cout << d2 << endl;
	cout << d3 << endl;
	system("pause");
	return 0;
}