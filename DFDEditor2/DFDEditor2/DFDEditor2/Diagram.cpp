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

void Diagram::add(Element* e){
	elems.push_back(e);
}
bool Diagram::Find(CPoint pos, Element *&e){
	vector<Element*>::iterator it;
	for (it = elems.begin(); it != elems.end(); it++){
		if ((*it)->Contains(pos)){
			e = (*it);
			return true;
		}
	}
	return false;
}
bool Diagram::FindStream(Element *e, list<Element*>&ElementQueue){
	return true;
}
HWND Diagram::SearchWnd(Element *e){
	HWND hWnd = NULL;
	map<Element*, HWND>::iterator it;
	for (it = proess2Diagram.begin(); it != proess2Diagram.end(); it++){
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
			if (tempse->CompareStartElementWith(e) && !tempse->startisInfieldof(e, pos)){
				tempse->setStartElement(NULL);
			}
			else if (tempse->CompareEndElementWith(e) && !tempse->endisInfieldof(e, pos)){
				tempse->setEndElement(NULL);
			}
			else{
				if (tempse->startisInfieldof(e, pos)){
					tempse->setStartElement(e);
				}
				if (tempse->endisInfieldof(e, pos)){
					(tempse->setEndElement(e));
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
				se->setStartElement(NULL);
			}
			else if ((*it)->Contains(pos)){
				se->setStartElement(*it);
			}
		}
	}
}
void Diagram::SetEndElementforStream(Stream *se, CPoint pos){
	vector<Element*>::iterator it;
	for (it = elems.begin(); it != elems.end(); it++){
		if (!(*it)->isStream() && (*it) != se){
			if (se->CompareEndElementWith((*it)) && !(*it)->Contains(pos)){
				se->setEndElement(NULL);
			}
			else if ((*it)->Contains(pos)){
				se->setEndElement(*it);
			}
		}
	}
}
void Diagram::Remove(Element *currente){
	
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
			startmidend[i][0] = tempse->getStart();
			startmidend[i][1] = tempse->getmidPoint();
			startmidend[i][2] = tempse->getEnd();
			i++;
		}
	}
}
void Diagram::InsertMap(Element *e, HWND hWnd){
	proess2Diagram.insert(pair<Element*, HWND>(e, hWnd));
}

void Diagram::FindStreams(queue<Element*>& elemq) //传入EndElement传出Stream
{
	vector<Element*>::iterator it;
	Stream* tmp;
	int endElemNum = elemq.size();
	for (it = elems.begin(); it != elems.end(),endElemNum > 0; it++){
		if ((*it)->isStream())
		{
			tmp = (Stream*)(*it);
			if (&elemq.front()->getmidPoint())  ///////////////////
			{

			}
		}
	}
}
