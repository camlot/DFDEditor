#include "stdafx.h"
#include "Diagram.h"
#include"Element.h"
#include"DFDStream.h"

Diagram::Diagram()
{
}


Diagram::~Diagram()
{
}

void Diagram::Add(Element* e){
	elems.push_back(e);
}
bool Diagram::Find(CPoint pos, Element *&e){
	vector<Element*>::iterator it;
	for (it = elems.begin(); it != elems.end(); it++){
		if ((*it)->isStream() && (*it)->Contains(pos)){
			e = (*it);
			return true;
		}
	}
	for (it = elems.begin(); it != elems.end(); it++){
		if ((*it)->Contains(pos)){
			e = (*it);
			return true;
		}
	}
	return false;
}


HWND Diagram::SearchWnd(Element *e){
	HWND hWnd = NULL;
	map<Element*, HWND>::iterator it;
	for (it = process2Diagram.begin(); it != process2Diagram.end(); it++){
		if (it->first == e){
			hWnd = it->second;
			break;
		}
	}
	return hWnd;
}
void Diagram::SetElementforStreambyElement(Element *e, CPoint pos){
	vector<Element*>::iterator it;
	for (it = elems.begin(); it != elems.end(); it++){
		if ((*it)->isStream()){
			Stream *tempse = (Stream*)(*it);
			if (tempse->CompareStartElementWith(e) && !tempse->StartisInfieldof(e, pos)){
				tempse->SetStartElement(NULL);
			}
			else if (tempse->CompareEndElementWith(e) && !tempse->EndisInfieldof(e, pos)){
				tempse->SetEndElement(NULL);
			}
			else{
				if (tempse->StartisInfieldof(e, pos)){
					tempse->SetStartElement(e);
					tempse->StartFollowElement(e);
				}
				if (tempse->EndisInfieldof(e, pos)){
					(tempse->SetEndElement(e));
					tempse->EndFollowElement(e);
				}
			}
		}
	}
}
void Diagram::SetStartElementforStream(Stream *se, CPoint pos){
	vector<Element*>::iterator it;
	for (it = elems.begin(); it != elems.end(); it++){
		if (!(*it)->isStream() && (*it) != se){
			if (se->CompareStartElementWith((*it)) && !(*it)->Contains(pos)){
				se->SetStartElement(NULL);
			}
			else if ((*it)->Contains(pos)){
				se->SetStartElement(*it);
				se->StartFollowElement((*it));
			}
		}
	}
}
void Diagram::SetEndElementforStream(Stream *se, CPoint pos){
	vector<Element*>::iterator it;
	for (it = elems.begin(); it != elems.end(); it++){
		if (!(*it)->isStream() && (*it) != se){
			if (se->CompareEndElementWith((*it)) && !(*it)->Contains(pos)){
				se->SetEndElement(NULL);
			}
			else if ((*it)->Contains(pos)){
				se->SetEndElement(*it);
				se->EndFollowElement((*it));
			}
		}
	}
}
void Diagram::Remove(Element *e){
	vector<Element*>::iterator it;
	if (e)
	{
		for (it = elems.begin(); it != elems.end();){
			if (e->getmidPoint() == (*it)->getmidPoint()){  // 如果图元的中点相同
				it = elems.erase(it);
			}
			else
			{
				it++;
			}
		}
	}

}
/*void Diagram::DrawDiagram(map<CPoint*, int>&drawdiagram){
	vector<Element*>::iterator it;
	for (it = elems.begin(); it != elems.end(); it++){
	drawdiagram.insert(pair<CPoint*, int>(&(*it)->midPoint, (*it)->type));
	}
	}*/


void Diagram::DrawDiagram(vector<CPoint>&poss, vector<int>&types, vector<CString>&strs,CPoint startmidend[][3]){

	vector<Element*>::iterator it;
	int i = 0;
	Stream *tempse;
	for (it = elems.begin(); it != elems.end(); it++){
		poss.push_back((*it)->getmidPoint());
		if ((*it)->isSource()) types.push_back(1);
		else if ((*it)->isProcess()) types.push_back(2);
		else if ((*it)->isDataStorage()) types.push_back(3);
		else types.push_back(4);
		strs.push_back((*it)->getText());
		if ((*it)->isStream()){
			tempse = (Stream*)(*it);
			startmidend[i][0] = tempse->GetStart();
			startmidend[i][1] = tempse->getmidPoint();
			startmidend[i][2] = tempse->GetEnd();
			i++;
		}
	}
}
void Diagram::InsertMap(Element *e, HWND hWnd){
	process2Diagram.insert(pair<Element*, HWND>(e, hWnd));
}

int Diagram::FindStreams(Element* currente, queue<Stream*>& elemq){
	vector<Element*>::iterator it;
	Stream* tmp(NULL);
	int flag(0); // start_end分界
	if (currente){  //节点不为空
		for (it = elems.begin(); it != elems.end(); it++){
			if ((*it)->isStream())
			{
				tmp = (Stream*)(*it);
				if (tmp->CompareStartElementWith(currente))  // Stream终点图元为传入图元时
				{
					elemq.push(tmp);  //传出流
					flag++;
				}
			}
		}
		for (it = elems.begin(); it != elems.end(); it++){
			if ((*it)->isStream())

			{
				tmp = (Stream*)(*it);
				if (tmp->CompareEndElementWith(currente))  // Stream终点图元为传入图元时
				{
					elemq.push(tmp);  //传出流
				}
			}
		}
	}
	return flag;
}

void Diagram::FindStreams(vector<Element*>& elemq) //传入EndElement传出所有Stream
{
	vector<Element*>::iterator it;
	Stream* tmp;
	vector<Element*> midElems = elemq;
	elemq.clear();
	int endElemNum = midElems.size();  //获取终点节点数目
	while (!midElems.empty()){  //中间节点不为空
		for (it = elems.begin(); it != elems.end(); it++){
			if ((*it)->isStream())

			{
				tmp = (Stream*)(*it);
				if (tmp->getEndElement()->getmidPoint() == midElems.front()->getmidPoint())  // Stream终点图元为传入图元时
				{
					elemq.push_back(tmp);  //传出流
					midElems.push_back(tmp->getStartElement());
				}
			}
		}
		midElems.erase(midElems.begin());  //第一个元素清除
		endElemNum--;
	}
}
