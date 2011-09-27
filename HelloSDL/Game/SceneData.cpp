#include "SceneData.h"
#include "Camera.h"
#include "../Managers/SceneGraphManager.h"

SceneGraphManager *createGraph()
{
	auto root = new Object();
	root->Name = "Root";

	auto triangle1 = new Object();
	triangle1->Name = "T1";

	auto m = new Matrix4x4f();
	m->Translate(0.0f, 0.0f, -4.0f);
	
	triangle1->transformation = m;

	auto v1 = new Vector3f(-0.5f, -0.5f, 0.0f);
	auto v2 = new Vector3f(0.0f, 0.5f, 0.0f);
	auto v3 = new Vector3f(0.5f, -0.5f, 0.0f);
	
	auto c1 = new Vector3f(1, 0, 0);
	auto c2 = new Vector3f(0, 1, 0);
	auto c3 = new Vector3f(0, 0, 1);

	triangle1->vertices->push_back(*v1);
	triangle1->vertices->push_back(*v2);
	triangle1->vertices->push_back(*v3);
	
	triangle1->colors->push_back(*c1);
	triangle1->colors->push_back(*c2);
	triangle1->colors->push_back(*c3);
	
	auto triangle2 = new Object();
	triangle2->Name = "T2";

	triangle2->vertices->push_back(*v1);
	triangle2->vertices->push_back(*v2);
	triangle2->vertices->push_back(*v3);
	
	triangle2->colors->push_back(*c1);
	triangle2->colors->push_back(*c1);
	triangle2->colors->push_back(*c1);
	triangle2->transformation = (new Matrix4x4f())->Translate(0, 0, -4.0f);

	triangle1->children->push_back(*triangle2);

	auto triangle3 = new Object();
	triangle3->Name = "T3";

	triangle3->vertices->push_back(*v1);
	triangle3->vertices->push_back(*v2);
	triangle3->vertices->push_back(*v3);
	
	triangle3->colors->push_back(*c2);
	triangle3->colors->push_back(*c2);
	triangle3->colors->push_back(*c2);
	triangle3->transformation = (new Matrix4x4f())->Translate(-2, 0, 0);

	triangle1->children->push_back(*triangle3);
	
	root->children->push_back(*triangle1);

	auto camera = new Camera();
	camera->Position = *(new Vector3f(0, 0, 0));
	camera->LookAt = *(new Vector3f(0, 0, -1));
	camera->Up = *(new Vector3f(1, 1, 0));

	return new SceneGraphManager(camera, root);
}