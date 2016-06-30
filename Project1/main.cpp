#include <stdio.h>
#include "tinyxml2.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace tinyxml2;
using namespace std;

struct GeometryData
{
		double PositionX;
		double PositionY;
		// ...
		double DirectionX
		double RotationX;
		// ...
};

GeometryData parseXML(const char fileName[])
{
	GeometryData d;
	d.PositionX = 42;  // parse actual values from XML file and assign to struct fields
	// ...
/*	double arr[4][4];
	tinyxml2::XMLDocument xml_doc;

	tinyxml2::XMLError eResult = xml_doc.LoadFile("test.xml");
	if (eResult != tinyxml2::XML_SUCCESS) return false;

	tinyxml2::XMLNode* root = xml_doc.FirstChildElement("root");
	if (root == nullptr) return false;

	tinyxml2::XMLElement* TI = root->FirstChildElement("ToothIndex");
	if (TI == nullptr) return false;

	tinyxml2::XMLElement* Position = TI->FirstChildElement("Position");
	if (Position == nullptr) return false;

		pos.x = std::stod(Position->Attribute("x"));
		pos.y = std::stod(Position->Attribute("y"));
		pos.z = std::stod(Position->Attribute("z"));



	tinyxml2::XMLElement* Direction = TI->FirstChildElement("Direction");
	if (Direction == nullptr) return false;

	dir.x = std::stod(Direction->Attribute("x"));
	dir.y = std::stod(Direction->Attribute("y"));
	dir.z = std::stod(Direction->Attribute("z"));

	tinyxml2::XMLElement* Rotation = TI->FirstChildElement("Rotation");
	if (Rotation == nullptr) return false;
	rot.x = std::stod(Rotation->Attribute("x"));

	Rotation = Rotation->NextSiblingElement("Rotation");
	if (Rotation == nullptr) return false;
	rot.y = std::stod(Rotation->Attribute("y"));

	Rotation = Rotation->NextSiblingElement("Rotation");
	if (Rotation == nullptr) return false;
	rot.z = std::stod(Rotation->Attribute("z"));


	tinyxml2::XMLElement* TransformMatrix = TI->FirstChildElement("TransformMatrix");
	if (TransformMatrix == nullptr) return false;
	arr[0][0] = std::stod(TransformMatrix->Attribute("m00"));
	arr[0][1] = std::stod(TransformMatrix->Attribute("m01"));
	arr[0][2] = std::stod(TransformMatrix->Attribute("m02"));
	arr[0][3] = std::stod(TransformMatrix->Attribute("m03"));
	arr[1][0] = std::stod(TransformMatrix->Attribute("m10"));
	arr[1][1] = std::stod(TransformMatrix->Attribute("m11"));
	arr[1][2] = std::stod(TransformMatrix->Attribute("m12"));
	arr[1][3] = std::stod(TransformMatrix->Attribute("m13"));
	arr[2][0] = std::stod(TransformMatrix->Attribute("m20"));
	arr[2][1] = std::stod(TransformMatrix->Attribute("m21"));
	arr[2][2] = std::stod(TransformMatrix->Attribute("m22"));
	arr[2][3] = std::stod(TransformMatrix->Attribute("m23"));
	arr[3][0] = std::stod(TransformMatrix->Attribute("m30"));
	arr[3][1] = std::stod(TransformMatrix->Attribute("m31"));
	arr[3][2] = std::stod(TransformMatrix->Attribute("m32"));
	arr[3][3] = std::stod(TransformMatrix->Attribute("m33"));

	tinyxml2::XMLElement* Xaxis = TI->FirstChildElement("Xaxis");
	if (Xaxis == nullptr) return false;

	xA.x = std::stod(Xaxis->Attribute("x"));
	xA.y = std::stod(Xaxis->Attribute("y"));
	xA.z = std::stod(Xaxis->Attribute("z"));

	tinyxml2::XMLElement* Yaxis = TI->FirstChildElement("Yaxis");
	if (Yaxis == nullptr) return false;

	yA.x = std::stod(Yaxis->Attribute("x"));
	yA.y = std::stod(Yaxis->Attribute("y"));
	yA.z = std::stod(Yaxis->Attribute("z"));

	tinyxml2::XMLElement* Zaxis = TI->FirstChildElement("Zaxis");
	if (Zaxis == nullptr) return false;

	zA.x = std::stod(Zaxis->Attribute("x"));
	zA.y = std::stod(Zaxis->Attribute("y"));
	zA.z = std::stod(Zaxis->Attribute("z"));
*/
	return d;
}

// struct position {
// 	double x, y, z;
// }pos;
//
// struct direction {
// 	double x, y, z;
// }dir;
//
// struct rotation {
// 	double x, y, z;
// }rot;
//
// struct xAxis {
// 	double x, y, z;
// }xA;
//
// struct yAxis {
// 	double x, y, z;
// }yA;
//
// struct zAxis {
// 	double x, y, z;
// }zA;



int main()
{
	GeometryData d0 = parseXML("01000_20160314_1152_Inselsberger_ImplantDirectionPosition_0.xml");
	GeometryData d1 = parseXML("01000_20160314_1152_Inselsberger_ImplantDirectionPosition_1.xml");
	GeometryData d2 = parseXML("01000_20160314_1152_Inselsberger_ImplantDirectionPosition_2.xml");
	GeometryData d3 = parseXML("01000_20160314_1152_Inselsberger_ImplantDirectionPosition_3.xml");


	return 0;
}
