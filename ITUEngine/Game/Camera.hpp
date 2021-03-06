#ifndef ITUENGINE_CAMERA_H
#define ITUENGINE_CAMERA_H

#include <Math/Vector3f.hpp>
#include <Events/Input/KeyPressedEvent.hpp>
#include <Events/Input/MouseMoveEvent.hpp>
#include <Events/Input/MouseClickEvent.hpp>
#include <Events/Interfaces/IEventListener.hpp>

class Camera : public IKeyboardEvent, public IMouseMoveEvent
{
public:
	Camera();
	~Camera();

	static const int gutter_px = 20;
	static const int speed = 1;

	//Up/Down scaling needed
	static const int updownfactor = 50;

	static const int min_x_ws_coord = 0;
	static const int min_y_ws_coord = 0;
	static const int max_x_ws_coord = 40;
	static const int max_y_ws_coord = 40;

	//Position and LookAt are points
	Vector3f Position;
	Vector3f LookAt;

	//Up is a direction vector, based on Position.
	Vector3f Up;

	// Moves the position of the camera to the new location.
	void MoveCamera3D(Vector3f *newPosition);

	//Rotates the camera around the x axis, of the LookAt vector. Positive is clockwise, negative is counter-clockwise.
	void PitchCamera(float radians);
	//Rotates the camera around the y axis, of the Up vector. Positive is clockwise, negative is counter-clockwise.
	void YawCamera(float radians);
	//Rotates the camera around the z axis, of the LookAt vector. Positive is clockwise, negative is counter-clockwise.
	void RollCamera(float radians);
	
	//Zooms the camera in or out, Zero is standard, Negative is out and Positive is in.
	/* Implemented as moving the camera in/out in a line parallel to the z axis, of the LookAt vector */
	void ZoomCamera(float distance);

	// Moves the camera in a direction.
	/* Implemented as moving the camera, up/down in a 2D plane, orthogonally to the z axis, of the LookAt vector */
	void MoveCameraUpDown2D(float distance);
	void MoveCameraLeftRight2D(float distance);

	void Update(unsigned int deltaT);


protected:
	void OnMotion(MouseMoveEvent *motion);
	void OnKeyDown(KeyPressedEvent *key);
	void OnKeyUp(KeyPressedEvent *key);

private:
	bool isLeftButtonDown;
	bool isRightButtonDown;

	bool grab_on;
	
	void ResetCamera();

	bool moveLeft;
	bool moveRight;
	bool moveUp;
	bool moveDown;
};

#endif