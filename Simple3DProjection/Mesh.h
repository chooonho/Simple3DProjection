#pragma once

class Mesh
{
	private:
		bool mIsWireFrame;
	public:
		bool getIsWireFrame() { return mIsWireFrame; }
		void setIsWireFrame(bool isWireFrame) { mIsWireFrame = isWireFrame; }
		virtual void draw() = 0;
};
