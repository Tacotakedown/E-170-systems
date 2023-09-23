#include "main.h"


extern "C" {
	MSFS_CALLBACK bool E170_systems_gauge_callback(FsContext ctx, int service_id, void* pData)
	{
		switch (service_id)
		{
		default:
			break;
		}
		return false;
	}
}