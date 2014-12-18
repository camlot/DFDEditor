#include "stdafx.h"
#include "Diagram.h"
#include"Element.h"

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
			if ((*it)->startisInfieldof(e, pos)){
				(*it)->setStartElement(e);
			}
			if ((*it)->endisInfieldof(e, pos)){
				((*it)->setEndElement(e));
			}
		}
	}
}
void Diagram::SetStartElementforStream(Element *e, CPoint pos){
	vector<Element*>::iterator it;
	for (it = elems.begin(); it != elems.end(); it++){
		if ((*it)->Contains(pos)){
			e->setStartElement(*it);
			break;
		}
	}
}
void Diagram::SetEndElementforStream(Element *e, CPoint pos){
	vector<Element*>::iterator it;
	for (it = elems.begin(); it != elems.end(); it++){
		if ((*it)->Contains(pos)){
			e->setEndElement(*it);
			break;
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

void Diagram::DrawDiagram(vector<CPoint*>&poss, vector<int>&types, vector<CString>&strs){
	vector<Element*>::iterator it;
	for (it = elems.begin(); it != elems.end(); it++){
		poss.push_back(&(*it)->midPoint);
		types.push_back((*it)->type);
		strs.push_back((*it)->text);
	}
}
void Diagram::InsertMap(Element *e, HWND hWnd){
	proess2Diagram.insert(pair<Element*, HWND>(e, hWnd));
}