// MESSAGE MIXER_PARAM_SET support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief MIXER_PARAM_SET message
 *
 * Mixer paraemter values to set
 */
struct MIXER_PARAM_SET : mavlink::Message {
    static constexpr msgid_t MSG_ID = 236;
    static constexpr size_t LENGTH = 52;
    static constexpr size_t MIN_LENGTH = 52;
    static constexpr uint8_t CRC_EXTRA = 139;
    static constexpr auto NAME = "MIXER_PARAM_SET";


    uint8_t target_system; /*< System ID */
    uint8_t target_component; /*< Component ID */
    uint16_t index; /*< Index of this onboard parameter */
    uint8_t mixer_group; /*< Access to different sets of mixers */
    uint16_t mixer_index; /*< Index of the mixer in the group */
    uint8_t mixer_sub_index; /*< Index of the sub mixer in the mixer */
    uint8_t mixer_type; /*< Implementation specific identifier for mixer type */
    uint16_t parameter_index; /*< Index of the parameter in a mixer or something else */
    uint8_t param_type; /*< Parameter type: see the MAV_PARAM_TYPE enum for supported data types. */
    std::array<char, 16> param_id; /*< Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string */
    std::array<float, 6> param_values; /*< Array of parameter values */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  target_system: " << +target_system << std::endl;
        ss << "  target_component: " << +target_component << std::endl;
        ss << "  index: " << index << std::endl;
        ss << "  mixer_group: " << +mixer_group << std::endl;
        ss << "  mixer_index: " << mixer_index << std::endl;
        ss << "  mixer_sub_index: " << +mixer_sub_index << std::endl;
        ss << "  mixer_type: " << +mixer_type << std::endl;
        ss << "  parameter_index: " << parameter_index << std::endl;
        ss << "  param_type: " << +param_type << std::endl;
        ss << "  param_id: \"" << to_string(param_id) << "\"" << std::endl;
        ss << "  param_values: [" << to_string(param_values) << "]" << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << param_values;                  // offset: 0
        map << index;                         // offset: 24
        map << mixer_index;                   // offset: 26
        map << parameter_index;               // offset: 28
        map << target_system;                 // offset: 30
        map << target_component;              // offset: 31
        map << mixer_group;                   // offset: 32
        map << mixer_sub_index;               // offset: 33
        map << mixer_type;                    // offset: 34
        map << param_type;                    // offset: 35
        map << param_id;                      // offset: 36
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> param_values;                  // offset: 0
        map >> index;                         // offset: 24
        map >> mixer_index;                   // offset: 26
        map >> parameter_index;               // offset: 28
        map >> target_system;                 // offset: 30
        map >> target_component;              // offset: 31
        map >> mixer_group;                   // offset: 32
        map >> mixer_sub_index;               // offset: 33
        map >> mixer_type;                    // offset: 34
        map >> param_type;                    // offset: 35
        map >> param_id;                      // offset: 36
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
