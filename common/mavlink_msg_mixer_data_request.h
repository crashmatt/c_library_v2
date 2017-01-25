#pragma once
// MESSAGE MIXER_DATA_REQUEST PACKING

#define MAVLINK_MSG_ID_MIXER_DATA_REQUEST 269

MAVPACKED(
typedef struct __mavlink_mixer_data_request_t {
 uint8_t target_system; /*< system ID of the target*/
 uint8_t target_component; /*< component ID of the target*/
 uint8_t mixer_group; /*< Access to different sets of mixers ie. onboard, failsafe, uavcan etc..*/
 uint8_t mixer_index; /*< Index of the mixer in the group*/
 uint8_t mixer_sub_index; /*< Index of the sub mixer in the mixer*/
 uint8_t parameter_index; /*< Index of the parameter in the mixer or sub mixer*/
 uint8_t data_type; /*< The requested data from the message*/
}) mavlink_mixer_data_request_t;

#define MAVLINK_MSG_ID_MIXER_DATA_REQUEST_LEN 7
#define MAVLINK_MSG_ID_MIXER_DATA_REQUEST_MIN_LEN 7
#define MAVLINK_MSG_ID_269_LEN 7
#define MAVLINK_MSG_ID_269_MIN_LEN 7

#define MAVLINK_MSG_ID_MIXER_DATA_REQUEST_CRC 129
#define MAVLINK_MSG_ID_269_CRC 129



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MIXER_DATA_REQUEST { \
	269, \
	"MIXER_DATA_REQUEST", \
	7, \
	{  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_mixer_data_request_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_mixer_data_request_t, target_component) }, \
         { "mixer_group", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_mixer_data_request_t, mixer_group) }, \
         { "mixer_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_mixer_data_request_t, mixer_index) }, \
         { "mixer_sub_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_mixer_data_request_t, mixer_sub_index) }, \
         { "parameter_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_mixer_data_request_t, parameter_index) }, \
         { "data_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_mixer_data_request_t, data_type) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MIXER_DATA_REQUEST { \
	"MIXER_DATA_REQUEST", \
	7, \
	{  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_mixer_data_request_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_mixer_data_request_t, target_component) }, \
         { "mixer_group", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_mixer_data_request_t, mixer_group) }, \
         { "mixer_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_mixer_data_request_t, mixer_index) }, \
         { "mixer_sub_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_mixer_data_request_t, mixer_sub_index) }, \
         { "parameter_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_mixer_data_request_t, parameter_index) }, \
         { "data_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_mixer_data_request_t, data_type) }, \
         } \
}
#endif

/**
 * @brief Pack a mixer_data_request message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system system ID of the target
 * @param target_component component ID of the target
 * @param mixer_group Access to different sets of mixers ie. onboard, failsafe, uavcan etc..
 * @param mixer_index Index of the mixer in the group
 * @param mixer_sub_index Index of the sub mixer in the mixer
 * @param parameter_index Index of the parameter in the mixer or sub mixer
 * @param data_type The requested data from the message
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mixer_data_request_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system, uint8_t target_component, uint8_t mixer_group, uint8_t mixer_index, uint8_t mixer_sub_index, uint8_t parameter_index, uint8_t data_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MIXER_DATA_REQUEST_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t(buf, 2, mixer_group);
	_mav_put_uint8_t(buf, 3, mixer_index);
	_mav_put_uint8_t(buf, 4, mixer_sub_index);
	_mav_put_uint8_t(buf, 5, parameter_index);
	_mav_put_uint8_t(buf, 6, data_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MIXER_DATA_REQUEST_LEN);
#else
	mavlink_mixer_data_request_t packet;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.mixer_group = mixer_group;
	packet.mixer_index = mixer_index;
	packet.mixer_sub_index = mixer_sub_index;
	packet.parameter_index = parameter_index;
	packet.data_type = data_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MIXER_DATA_REQUEST_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_MIXER_DATA_REQUEST;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MIXER_DATA_REQUEST_MIN_LEN, MAVLINK_MSG_ID_MIXER_DATA_REQUEST_LEN, MAVLINK_MSG_ID_MIXER_DATA_REQUEST_CRC);
}

/**
 * @brief Pack a mixer_data_request message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system system ID of the target
 * @param target_component component ID of the target
 * @param mixer_group Access to different sets of mixers ie. onboard, failsafe, uavcan etc..
 * @param mixer_index Index of the mixer in the group
 * @param mixer_sub_index Index of the sub mixer in the mixer
 * @param parameter_index Index of the parameter in the mixer or sub mixer
 * @param data_type The requested data from the message
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mixer_data_request_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,uint8_t target_component,uint8_t mixer_group,uint8_t mixer_index,uint8_t mixer_sub_index,uint8_t parameter_index,uint8_t data_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MIXER_DATA_REQUEST_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t(buf, 2, mixer_group);
	_mav_put_uint8_t(buf, 3, mixer_index);
	_mav_put_uint8_t(buf, 4, mixer_sub_index);
	_mav_put_uint8_t(buf, 5, parameter_index);
	_mav_put_uint8_t(buf, 6, data_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MIXER_DATA_REQUEST_LEN);
#else
	mavlink_mixer_data_request_t packet;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.mixer_group = mixer_group;
	packet.mixer_index = mixer_index;
	packet.mixer_sub_index = mixer_sub_index;
	packet.parameter_index = parameter_index;
	packet.data_type = data_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MIXER_DATA_REQUEST_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_MIXER_DATA_REQUEST;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MIXER_DATA_REQUEST_MIN_LEN, MAVLINK_MSG_ID_MIXER_DATA_REQUEST_LEN, MAVLINK_MSG_ID_MIXER_DATA_REQUEST_CRC);
}

/**
 * @brief Encode a mixer_data_request struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mixer_data_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mixer_data_request_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mixer_data_request_t* mixer_data_request)
{
	return mavlink_msg_mixer_data_request_pack(system_id, component_id, msg, mixer_data_request->target_system, mixer_data_request->target_component, mixer_data_request->mixer_group, mixer_data_request->mixer_index, mixer_data_request->mixer_sub_index, mixer_data_request->parameter_index, mixer_data_request->data_type);
}

/**
 * @brief Encode a mixer_data_request struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mixer_data_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mixer_data_request_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mixer_data_request_t* mixer_data_request)
{
	return mavlink_msg_mixer_data_request_pack_chan(system_id, component_id, chan, msg, mixer_data_request->target_system, mixer_data_request->target_component, mixer_data_request->mixer_group, mixer_data_request->mixer_index, mixer_data_request->mixer_sub_index, mixer_data_request->parameter_index, mixer_data_request->data_type);
}

/**
 * @brief Send a mixer_data_request message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system system ID of the target
 * @param target_component component ID of the target
 * @param mixer_group Access to different sets of mixers ie. onboard, failsafe, uavcan etc..
 * @param mixer_index Index of the mixer in the group
 * @param mixer_sub_index Index of the sub mixer in the mixer
 * @param parameter_index Index of the parameter in the mixer or sub mixer
 * @param data_type The requested data from the message
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mixer_data_request_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t mixer_group, uint8_t mixer_index, uint8_t mixer_sub_index, uint8_t parameter_index, uint8_t data_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MIXER_DATA_REQUEST_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t(buf, 2, mixer_group);
	_mav_put_uint8_t(buf, 3, mixer_index);
	_mav_put_uint8_t(buf, 4, mixer_sub_index);
	_mav_put_uint8_t(buf, 5, parameter_index);
	_mav_put_uint8_t(buf, 6, data_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_DATA_REQUEST, buf, MAVLINK_MSG_ID_MIXER_DATA_REQUEST_MIN_LEN, MAVLINK_MSG_ID_MIXER_DATA_REQUEST_LEN, MAVLINK_MSG_ID_MIXER_DATA_REQUEST_CRC);
#else
	mavlink_mixer_data_request_t packet;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.mixer_group = mixer_group;
	packet.mixer_index = mixer_index;
	packet.mixer_sub_index = mixer_sub_index;
	packet.parameter_index = parameter_index;
	packet.data_type = data_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_DATA_REQUEST, (const char *)&packet, MAVLINK_MSG_ID_MIXER_DATA_REQUEST_MIN_LEN, MAVLINK_MSG_ID_MIXER_DATA_REQUEST_LEN, MAVLINK_MSG_ID_MIXER_DATA_REQUEST_CRC);
#endif
}

/**
 * @brief Send a mixer_data_request message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_mixer_data_request_send_struct(mavlink_channel_t chan, const mavlink_mixer_data_request_t* mixer_data_request)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_mixer_data_request_send(chan, mixer_data_request->target_system, mixer_data_request->target_component, mixer_data_request->mixer_group, mixer_data_request->mixer_index, mixer_data_request->mixer_sub_index, mixer_data_request->parameter_index, mixer_data_request->data_type);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_DATA_REQUEST, (const char *)mixer_data_request, MAVLINK_MSG_ID_MIXER_DATA_REQUEST_MIN_LEN, MAVLINK_MSG_ID_MIXER_DATA_REQUEST_LEN, MAVLINK_MSG_ID_MIXER_DATA_REQUEST_CRC);
#endif
}

#if MAVLINK_MSG_ID_MIXER_DATA_REQUEST_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_mixer_data_request_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint8_t mixer_group, uint8_t mixer_index, uint8_t mixer_sub_index, uint8_t parameter_index, uint8_t data_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t(buf, 2, mixer_group);
	_mav_put_uint8_t(buf, 3, mixer_index);
	_mav_put_uint8_t(buf, 4, mixer_sub_index);
	_mav_put_uint8_t(buf, 5, parameter_index);
	_mav_put_uint8_t(buf, 6, data_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_DATA_REQUEST, buf, MAVLINK_MSG_ID_MIXER_DATA_REQUEST_MIN_LEN, MAVLINK_MSG_ID_MIXER_DATA_REQUEST_LEN, MAVLINK_MSG_ID_MIXER_DATA_REQUEST_CRC);
#else
	mavlink_mixer_data_request_t *packet = (mavlink_mixer_data_request_t *)msgbuf;
	packet->target_system = target_system;
	packet->target_component = target_component;
	packet->mixer_group = mixer_group;
	packet->mixer_index = mixer_index;
	packet->mixer_sub_index = mixer_sub_index;
	packet->parameter_index = parameter_index;
	packet->data_type = data_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_DATA_REQUEST, (const char *)packet, MAVLINK_MSG_ID_MIXER_DATA_REQUEST_MIN_LEN, MAVLINK_MSG_ID_MIXER_DATA_REQUEST_LEN, MAVLINK_MSG_ID_MIXER_DATA_REQUEST_CRC);
#endif
}
#endif

#endif

// MESSAGE MIXER_DATA_REQUEST UNPACKING


/**
 * @brief Get field target_system from mixer_data_request message
 *
 * @return system ID of the target
 */
static inline uint8_t mavlink_msg_mixer_data_request_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from mixer_data_request message
 *
 * @return component ID of the target
 */
static inline uint8_t mavlink_msg_mixer_data_request_get_target_component(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field mixer_group from mixer_data_request message
 *
 * @return Access to different sets of mixers ie. onboard, failsafe, uavcan etc..
 */
static inline uint8_t mavlink_msg_mixer_data_request_get_mixer_group(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field mixer_index from mixer_data_request message
 *
 * @return Index of the mixer in the group
 */
static inline uint8_t mavlink_msg_mixer_data_request_get_mixer_index(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field mixer_sub_index from mixer_data_request message
 *
 * @return Index of the sub mixer in the mixer
 */
static inline uint8_t mavlink_msg_mixer_data_request_get_mixer_sub_index(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field parameter_index from mixer_data_request message
 *
 * @return Index of the parameter in the mixer or sub mixer
 */
static inline uint8_t mavlink_msg_mixer_data_request_get_parameter_index(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field data_type from mixer_data_request message
 *
 * @return The requested data from the message
 */
static inline uint8_t mavlink_msg_mixer_data_request_get_data_type(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Decode a mixer_data_request message into a struct
 *
 * @param msg The message to decode
 * @param mixer_data_request C-struct to decode the message contents into
 */
static inline void mavlink_msg_mixer_data_request_decode(const mavlink_message_t* msg, mavlink_mixer_data_request_t* mixer_data_request)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	mixer_data_request->target_system = mavlink_msg_mixer_data_request_get_target_system(msg);
	mixer_data_request->target_component = mavlink_msg_mixer_data_request_get_target_component(msg);
	mixer_data_request->mixer_group = mavlink_msg_mixer_data_request_get_mixer_group(msg);
	mixer_data_request->mixer_index = mavlink_msg_mixer_data_request_get_mixer_index(msg);
	mixer_data_request->mixer_sub_index = mavlink_msg_mixer_data_request_get_mixer_sub_index(msg);
	mixer_data_request->parameter_index = mavlink_msg_mixer_data_request_get_parameter_index(msg);
	mixer_data_request->data_type = mavlink_msg_mixer_data_request_get_data_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MIXER_DATA_REQUEST_LEN? msg->len : MAVLINK_MSG_ID_MIXER_DATA_REQUEST_LEN;
        memset(mixer_data_request, 0, MAVLINK_MSG_ID_MIXER_DATA_REQUEST_LEN);
	memcpy(mixer_data_request, _MAV_PAYLOAD(msg), len);
#endif
}
