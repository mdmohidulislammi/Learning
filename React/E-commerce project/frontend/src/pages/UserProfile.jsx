import React, { useState, useEffect, useContext } from "react";
import { AuthContext } from "../context/AuthContext";
import Title from "../components/Title";

const UserProfile = () => {
  const { user, api, refreshUser } = useContext(AuthContext);
  const [profile, setProfile] = useState({
    full_name: "",
    location: "",
    country: "",
    cell: "",
  });
  const [loading, setLoading] = useState(true);
  const [saving, setSaving] = useState(false);
  const [message, setMessage] = useState({ type: "", text: "" });

  useEffect(() => {
    if (user && user.user_id) {
      fetchProfile();
    }
  }, [user]);

  const fetchProfile = async () => {
    try {
      const res = await api.get(`/user/profile/${user.user_id}/`);
      setProfile({
        full_name: res.data.full_name || "",
        location: res.data.location || "",
        country: res.data.country || "",
        cell: res.data.cell || "",
      });
    } catch (err) {
      console.error("Failed to load profile", err);
      let errorMsg = "Could not load profile.";
      if (err.response) {
        if (err.response.status === 404) {
          errorMsg = "Profile not found. Please try saving your details once.";
        } else if (err.response.data?.detail) {
          errorMsg = err.response.data.detail;
        } else {
          errorMsg = `Server error: ${err.response.status}`;
        }
      } else if (err.request) {
        errorMsg = "No response from server.";
      }
      setMessage({ type: "error", text: errorMsg });
    } finally {
      setLoading(false);
    }
  };

  const handleChange = (e) => {
    setProfile({ ...profile, [e.target.name]: e.target.value });
  };

  // Format phone number for Bangladesh (+880XXXXXXXXX)
  const formatPhoneNumber = (phone) => {
    if (!phone) return "";
    let cleaned = phone.replace(/\s/g, "");
    if (cleaned.startsWith("+")) return cleaned;
    if (cleaned.startsWith("880")) return "+" + cleaned;
    if (cleaned.startsWith("0")) return "+88" + cleaned.slice(1);
    return "+88" + cleaned;
  };

  const handleSubmit = async (e) => {
    e.preventDefault();
    setSaving(true);
    setMessage({ type: "", text: "" });

    const dataToSend = {
      full_name: profile.full_name,
      location: profile.location,
      country: profile.country,
      cell: formatPhoneNumber(profile.cell),
    };

    try {
      const res = await api.patch(`/user/profile/update/${user.user_id}/`, dataToSend);
      setMessage({ type: "success", text: "Profile updated successfully!" });
      await refreshUser();
      setTimeout(() => setMessage({ type: "", text: "" }), 3000);
    } catch (err) {
      console.error("Update error:", err.response?.data);
      let errorMsg = "Failed to update profile.";
      if (err.response?.data) {
        const data = err.response.data;
        if (data.cell) errorMsg = `Phone number error: ${data.cell[0]}`;
        else if (data.full_name) errorMsg = data.full_name[0];
        else if (data.location) errorMsg = data.location[0];
        else if (data.country) errorMsg = data.country[0];
        else if (data.detail) errorMsg = data.detail;
        else errorMsg = JSON.stringify(data);
      }
      setMessage({ type: "error", text: errorMsg });
    } finally {
      setSaving(false);
    }
  };

  if (loading) return <div className="my-10 text-center">Loading profile...</div>;

  return (
    <div className="my-10 max-w-2xl mx-auto px-4">
      <Title text1={"MY"} text2={"PROFILE"} />
      <form onSubmit={handleSubmit} className="space-y-5 bg-white p-6 rounded-lg shadow-md mt-6">
        <div>
          <label className="block text-sm font-medium text-gray-700 mb-1">Full Name</label>
          <input
            type="text"
            name="full_name"
            value={profile.full_name}
            onChange={handleChange}
            className="w-full border border-gray-300 rounded-md px-4 py-2"
          />
        </div>
        <div>
          <label className="block text-sm font-medium text-gray-700 mb-1">Email</label>
          <input
            type="email"
            value={user?.email || ""}
            disabled
            className="w-full border border-gray-300 rounded-md px-4 py-2 bg-gray-100"
          />
          <p className="text-xs text-gray-500 mt-1">Email cannot be changed.</p>
        </div>
        <div>
          <label className="block text-sm font-medium text-gray-700 mb-1">Delivery Address</label>
          <input
            type="text"
            name="location"
            value={profile.location}
            onChange={handleChange}
            className="w-full border border-gray-300 rounded-md px-4 py-2"
          />
        </div>
        <div>
          <label className="block text-sm font-medium text-gray-700 mb-1">Country</label>
          <input
            type="text"
            name="country"
            value={profile.country}
            onChange={handleChange}
            className="w-full border border-gray-300 rounded-md px-4 py-2"
          />
        </div>
        <div>
          <label className="block text-sm font-medium text-gray-700 mb-1">Phone Number</label>
          <input
            type="tel"
            name="cell"
            value={profile.cell}
            onChange={handleChange}
            placeholder="+8801712345678"
            className="w-full border border-gray-300 rounded-md px-4 py-2"
          />
          <p className="text-xs text-gray-500 mt-1">Format: +880XXXXXXXXX</p>
        </div>

        {message.text && (
          <div className={`p-3 rounded-md ${message.type === "success" ? "bg-green-100 text-green-700" : "bg-red-100 text-red-700"}`}>
            {message.text}
          </div>
        )}

        <button
          type="submit"
          disabled={saving}
          className="w-full bg-blue-600 text-white py-2 rounded-md hover:bg-blue-700 transition disabled:bg-gray-400"
        >
          {saving ? "Saving..." : "Save Changes"}
        </button>
      </form>
    </div>
  );
};

export default UserProfile;